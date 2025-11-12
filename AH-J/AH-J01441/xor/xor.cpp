#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s1=0,s0=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            s1++;
        }else{
            s0++;
        }
    }
    if(k==0){
        if(s1==n){
            cout<<0;
        }else if(s0==n){
            cout<<n;
        }else{
            cout<<s0;
        }
    }else if(k==1){
        if(s1==n){
            cout<<n;
        }else if(s0==n){
            cout<<0;
        }else{
            cout<<s1;
        }
    }
    return 0;
}
