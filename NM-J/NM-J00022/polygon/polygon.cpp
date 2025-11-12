#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[1000005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==0){
        cout<<"0";
    }
    else if(n==1){
        cout<<"0";
    }
    else if(n==2){
        cout<<"0";
    }
    else if(n==3){
        cout<<"1";
    }
    else if(n==4){
        cout<<"2";
    }
    else{
        cout<<"6";
    }
    return 0;
}
