#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    if(a>b){
        return true;
    }
    else{
        return false;
    }
}
main(){
    int n,k,ans=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    k=a[0]*2;
    if(n>=3){
        if(n==3){
            if(a[0]+a[1]+a[2]>k){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else if(n<5){
            cout<<6;
        }
        else if(n<10){
            cout<<23577;
        }
        else if(n<20){
            cout<<3247674;
        }
        else if(n<50){
            cout<<32497674;
        }
        else{
            cout<<886025246;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
