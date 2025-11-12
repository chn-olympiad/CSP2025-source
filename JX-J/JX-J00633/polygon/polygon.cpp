#include<iostream>
using namespace std;
int e[101010];
int main(){
    int a,b=3,c=0,d=0;
    cin>>a;
    b=2;
    for(int i=1;i<=a;i++){
        cin>>e[i];
        if(e[i]>c){
            c=e[i];
        }
    }
    for(int i=1;i<=3;i++){
        if(e[i]+e[i+1]+e[i+2]>c*2){
            d++;
        }
    }
    cout<<d;
}
