#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray(); //IMPLEMENTADO
    CircularArray(int _capacity); //IMPLEMENTADO
    virtual ~CircularArray(); //IMPLEMENTADO
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full(); // IMPLEMENTADO
    bool is_empty(); // IMPLEMENTADO
    int size(); // IMPLEMENTADO
    void clear(); //IMPLEMENTADO
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" "); //IMPLEMENTADO

private:
    int next(int); //IMPLEMENTADO
    int prev(int); //IMPLEMENTADO
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string(array[i]) + sep;
    return result;    
}

template<class T>
void CircularArray<T>::push_front(T data){
    if(size() == capacity){
        cout<<"NO PUEDES AGREGAR MAS ELEMENTOS QUE LOS PERMITIDOS";
    }
    else{
        if( back <= 0 ){
            T* temp = new T[capacity];
            for(int i=0; i<size(); i++)
                temp[i] = array[i];
            for(int i=0; i<size(); i++)
                array[i+1] = temp[i];
            array[0] = data;
            delete temp;
            front++;
        }else{
            array[--back] = data;
        }
    }
}

template<class T>
void CircularArray<T>::push_back(T data){
    if(size() == capacity){
        cout<<"NO PUEDES AGREGAR MAS ELEMENTOS QUE LOS PERMITIDOS";
    }
    else{
        int n = front;
        array[++n] = data;
        if(size() == 0)
            back = 0;
        front = n;
    }
}

template<class T>
void CircularArray<T>::insert(T data, int pos){

}

template<class T>
T CircularArray<T>::pop_front(){
    T element = array[back];
    array[back] = 0;
    ++back;
    return element;
}

template<class T>
T CircularArray<T>::pop_back(){
    T element = array[front];
    array[front] = 0;
    --front;
    return element;
}

template<class T>
bool CircularArray<T>::is_full()
{
    return (size() == capacity) ? true : false;
}

template<class T>
bool CircularArray<T>::is_empty()
{
    return (size() == 0) ? true : false;
}

template<class T>
int CircularArray<T>::size()
{
    return (front == -1 && back == -1) ? front-back : front-back+1;
}

template<class T>
void CircularArray<T>::clear()
{
    T* temp = new T[capacity];
    array = temp;
    delete temp;
}

template<class T>
T& CircularArray<T>::operator[](int)
{
    T* element = nullptr;
    return *element;
}

template<class T>
void CircularArray<T>::sort()
{
    for (int i = 0; i < size()-1; i++)     
    // Last i elements are already in place 
    for (int j = 0; j < size()-i-1; j++) 
        if (array[j] > array[j+1]){ 
            T temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        } 
}

template<class T>
bool CircularArray<T>::is_sorted()
{
    if(size()<=1)
        return true;
    for(int i=0; i<size() ; i++){
        if(array[i] > array[i+1])
            return false;
    }
    return true;
}

template<class T>
void CircularArray<T>::reverse()
{
    T* temp = new T[capacity];
    for(int i=0; i<size() ; i++) 
        temp[i]=array[size()-(i+1)];
    array = temp;
}