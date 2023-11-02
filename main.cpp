#include <iostream>
#include <vector>
using namespace std;

class SET {
public:
    vector<int> set_elements;

    void sort(SET &t){
    int d=t.set_elements.size();
    for(int i = 0; i < d- 1; i++) {
        for (int j = 0; j < d- i - 1; j++) {
            if (t.set_elements[j] > t.set_elements[j + 1]) {
              
                int temp = t.set_elements[j];
                t.set_elements[j] = t.set_elements[j + 1];
                t.set_elements[j + 1] = temp;
            }
        }
    }
}
  

    void insert(SET& t, int data) {
        for (int j = 0; j < t.set_elements.size(); j++) {
            if (data == t.set_elements[j]) {
                cout << t.set_elements.size() << endl;
                return;
            }
        }

        t.set_elements.push_back(data);
        cout << t.set_elements.size() << endl;
    }

    void Delete(SET& t, int data) {
        if (t.set_elements.size() == 0) {
            cout << 0 << endl;
            return;
        }

        for (int j = 0; j < t.set_elements.size(); j++) {
            if (data == t.set_elements[j]) {
                t.set_elements.erase(t.set_elements.begin() + j);
                break;
            }
        }
        cout << t.set_elements.size() << endl;
    }

    void Belongs_to(SET& t, int data) {
        if (t.set_elements.size() == 0) {
            cout << 0 << endl;
            return;
        }

        for (int j = 0; j < t.set_elements.size(); j++) {
            if (data == t.set_elements[j]) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 0 << endl;
    }

    void Union(SET& t, SET& q) {
        vector<int> newvec;
        int i = 0;
        int j = 0;

        while (i < t.set_elements.size() && j < q.set_elements.size()) {
            if (t.set_elements[i] < q.set_elements[j]) {
                newvec.push_back(t.set_elements[i]);
                i = i + 1;
            } else if (q.set_elements[j] < t.set_elements[i]) {
                newvec.push_back(q.set_elements[j]);
                j = j + 1;
            } else if (t.set_elements[i] == q.set_elements[j]) {
                newvec.push_back(t.set_elements[i]);
                i = i + 1;
                j = j + 1;
            }
        }

        while (i < t.set_elements.size()) {
            newvec.push_back(t.set_elements[i]);
            i = i + 1;
        }

        while (j < q.set_elements.size()) {
            newvec.push_back(q.set_elements[j]);
            j = j + 1;
        }

        t.set_elements = newvec;
        cout << t.set_elements.size() << endl;
    }

    void intersection(SET& t, SET& q) {
        vector<int> newvec;
        int i = 0;
        int j = 0;

        while (i < t.set_elements.size() && j < q.set_elements.size()) {
            if (t.set_elements[i] == q.set_elements[j]) {
                newvec.push_back(t.set_elements[i]);
                i = i + 1;
                j = j + 1;
            } else if (t.set_elements[i] < q.set_elements[j]) {
                i = i + 1;
            } else {
                j = j + 1;
            }
        }

        t.set_elements = newvec;
        cout << t.set_elements.size() << endl;
    }

    void size(SET& t) {
        cout << t.set_elements.size() << endl;
    }

    void difference(SET& t, SET& q) {
        vector<int> newvec;
        int i = 0;
        int j = 0;

        while (i < t.set_elements.size() && j < q.set_elements.size()) {
            if (t.set_elements[i] == q.set_elements[j]) {
                i = i + 1;
                j = j + 1;
            } else if (t.set_elements[i] < q.set_elements[j]) {
                newvec.push_back(t.set_elements[i]);
                i = i + 1;
            } else {
                j = j + 1;
            }
        }

        while (i < t.set_elements.size()) {
            newvec.push_back(t.set_elements[i]);
            i = i + 1;
        }

        t.set_elements = newvec;
        cout << t.set_elements.size() << endl;
    }

    void symmetric_difference(SET& t, SET& q) {
        vector<int> newvec;
        int i = 0;
        int j = 0;

        while (i < t.set_elements.size() && j < q.set_elements.size()) {
            if (t.set_elements[i] < q.set_elements[j]) {
                newvec.push_back(t.set_elements[i]);
                i = i + 1;
            } else if (q.set_elements[j] < t.set_elements[i]) {
                newvec.push_back(q.set_elements[j]);
                j = j + 1;
            } else if (t.set_elements[i] == q.set_elements[j]) {
                i = i + 1;
                j = j + 1;
            }
        }

        while (i < t.set_elements.size()) {
            newvec.push_back(t.set_elements[i]);
            i = i + 1;
        }

        while (j < q.set_elements.size()) {
            newvec.push_back(q.set_elements[j]);
            j = j + 1;
        }

        t.set_elements = newvec;
        cout << t.set_elements.size() << endl;
    }

    void print(SET& t) {
        if (t.set_elements.size() == 0) {
            cout << endl;
        }
        else{
        for (int i = 0; i < t.set_elements.size(); i++) {
            cout << t.set_elements[i];
            if (i < t.set_elements.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
        }
    }
};

int main() {
    vector<SET> sets;
    SET set_nums;
    int command;
    while(cin>>command){
   
    if(command==1){
        int index; //the no. of set in which to store data
        
        cin>>index;
        int data;
        
        cin>>data;
        if(index<sets.size()){
            set_nums.insert(sets[index],data);
        }
        else{
            sets.push_back(set_nums);
            set_nums.insert(sets[index],data);
            set_nums.sort(sets[index]);
        }
    }
    else if(command==2){
         int index; //the no. of set in which to store data
        
        cin>>index;
        int data;
        
        cin>>data;
        if(index>=sets.size()){
            sets.push_back(set_nums);
            cout<<-1<<endl;
        }
        else{
            set_nums.Delete(sets[index],data);
            set_nums.sort(sets[index]);
            
        }
    }
        else if(command==3){
           int index; //the no. of set in which to store data
        
        cin>>index;
        int data;
        
        cin>>data;
        if(index>=sets.size()){
            cout<<-1<<endl;
        }
        else{
            set_nums.Belongs_to(sets[index],data);
            set_nums.sort(sets[index]);
        }
    }
    else if(command==4){
        int index_one; //the no. of set in which to store data
        
        cin>>index_one;
         int index_two; //the no. of set in which to store data
        
        cin>>index_two;
         if(index_one>=sets.size()){
             sets.push_back(set_nums);
         }
         else if(index_two>=sets.size()){
             sets.push_back(set_nums);
         }
         else if(index_one>=sets.size()&&index_two>=sets.size()){
             sets.push_back(set_nums);
             sets.push_back(set_nums);
         }
         else{
             set_nums.Union(sets[index_one],sets[index_two]);
            
         }
    }
    else if(command==5){
     int index_one; //the no. of set in which to store data
        
        cin>>index_one;
         int index_two; //the no. of set in which to store data
        
        cin>>index_two;
         if(index_one>=sets.size()){
             sets.push_back(set_nums);
         }
         else if(index_two>=sets.size()){
             sets.push_back(set_nums);
         }
         else if(index_one>=sets.size()&&index_two>=sets.size()){
             sets.push_back(set_nums);
             sets.push_back(set_nums);
         }
         else{
             set_nums.intersection(sets[index_one],sets[index_two]);
             set_nums.sort(sets[index_one]);
         }   
    }
    else if(command==6){
        int index; //the no. of set in which to store data
        
        cin>>index;
        if(index>=sets.size()){
            sets.push_back(set_nums);
            cout<<0<<endl;
        }
        else
        set_nums.size(sets[index]);
        set_nums.sort(sets[index]);
    }
    else if(command==7){
     int index_one; //the no. of set in which to store data
        
        cin>>index_one;
         int index_two; //the no. of set in which to store data
        
        cin>>index_two;
         if(index_one>=sets.size()){
             sets.push_back(set_nums);
         }
         else if(index_two>=sets.size()){
             sets.push_back(set_nums);
         }
         else if(index_one>=sets.size()&&index_two>=sets.size()){
             sets.push_back(set_nums);
             sets.push_back(set_nums);
         }
         else{
             set_nums.difference(sets[index_one],sets[index_two]);
             set_nums.sort(sets[index_one]);
         }    
    }
     else if(command==8){
        int index_one; //the no. of set in which to store data
        
        cin>>index_one;
         int index_two; //the no. of set in which to store data
        
        cin>>index_two;
         if(index_one>=sets.size()){
             sets.push_back(set_nums);
             
         }
         else if(index_two>=sets.size()){
             sets.push_back(set_nums);
           
         }
         else if(index_one>=sets.size()&&index_two>=sets.size()){
             sets.push_back(set_nums);
             sets.push_back(set_nums);
            
         }
         else{
             
             set_nums.symmetric_difference(sets[index_one],sets[index_two]);
            
         }  
     }
    else if(command==9){
        int index; //the no. of set in which to store data
        
        cin>>index;
        if(index>=sets.size()){
            cout<<endl;
        }
            else {
                set_nums.sort(sets[index]);
                set_nums.print(sets[index]);          
            }
            
        }
    
    }
}