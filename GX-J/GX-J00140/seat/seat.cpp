#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r","stdin");
    freopen("seat.out","w","stdout");
    int a,b,cnt=0;
    cin>>a>>b;
    int c=a*b;
    int d[c];
    for(int i=1;i<=c;i++){
        cin>>d[i];
    }
    for(int i=2;i<=c;i++){
        if(d[i]>d[1]){
            cnt++;
        }
    }int e=cnt/a;
    if(e%2==1){
        if(cnt%2==0){
            int f=a;
            cout<<e+1<<" "<<f;
        }else{
            int f=a-(cnt%a);
            cout<<e+1<<" "<<f;
        }
    }else{
        if(cnt%2==0){
            int f=1;
            cout<<e+1<<" "<<f;
        }else{
            int f=cnt%a;
            cout<<e+1<<" "<<f+1;
        }
    }
    return 0;
}
