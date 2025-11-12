#include<iostream>
using namespace std;
int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]<a[i+1]){
            cout<<a[i+1]<<a[i];
        }
    }
    return 0;
}
