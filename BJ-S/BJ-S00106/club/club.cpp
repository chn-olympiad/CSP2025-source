#include <iostream>
#include <vector>

using namespace std;

long long val=-2147;
long long rand_val(){
    val+=9223371;
    val^=(val^103*(val)-214748364);
    val-=36437759;
    return val;
}

template<class T>
vector<T> smooth(vector<T>data, int val){
    vector<T> new_data;
    for(int i = 0;i<int(data.size()-val);i++){
        T avg=0;
        for (int j = 0;j<val;j++){
            avg+=data[i+j];
        }
        avg/=val;
        new_data.push_back(avg);
    }
    T max_val=0;
    T min_val=0;
    for (T d:new_data){
        if(max_val<(d))max_val=(d);
        if(min_val>(d))min_val=(d);
    }
    for (T o=0;o<new_data.size();o++){
        new_data[o]=2*(new_data[o]-min_val)/(max_val-min_val)-1;
    }

    return new_data;
}

int main(){
    vector<double> frag;
    for (int i = 0;i<1000;i++){
        frag.push_back(rand_val()/(2147483648.0d*2147483648.0d));
    }
    for (int i = 0;i<2;i++){
        frag=smooth(frag, 11);
    }
    /*
    for (double i:frag){
        for (int j = 0;j<int((i/2+0.5)*70);j++){
            cout << '#';
        }
        cout << i<<endl;
    }
    */

    /*
    int box[30]={};
    for (double i:frag){
        box[int((i/2+0.5)*29)]++;
    }
    for (int i = 0;i<30;i++){
        cout << box[i] << endl;
    }
    */
    
}