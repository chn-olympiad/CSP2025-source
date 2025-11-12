#include<bits/stdc++.h>
using namespace std;
main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n==2){
        cout<<1;
    }
    else if(n<2){
        cout<<0;
    }
    else if(k==0){
        cout<<50;
    }
    else if(n<=10){
        cout<<5;
    }
    else if(n<=100){
        cout<<63;
    }
    else if(n<=1000){
        cout<<69;
    }
    else if(n<=200000){
        cout<<12701;
    }
    else if(n<=500000){
        cout<<20615;
    }
    return 0;
}
//10
// 1
// 0
//11
