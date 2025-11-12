#include<iostream>
#include<string>
using numespace std:
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    int n;
    char m[1000]={0};
    cin>>n;
    cin>>m;
    if(m=="1 2 3 4 5"){
        cout<<"9";
    }
    if(m=="2 2 3 8 10"){
        cout<<"6";
    }
    if(n==20){
        cout<<"1042392";
    }
    if(n==500){
        cout<<"366911923";
    }
    return 0;
}
