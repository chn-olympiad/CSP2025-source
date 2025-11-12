#include<bits/stdc++.h>
using namespace std;
int sz[500100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int pd1=1,pd2=1;
    for(int i=1;i<=n;i++){
        cin>>sz[i];
        if(sz[i]!=1){
            pd1=0;
            if(sz[i]!=0){
                pd2=0;
            }
        }
    }if(n==2){
        if(sz[1]==k){
            int ans=1;
            if(sz[2]==k){
                ans++;
            }cout<<ans;
        }else{
            if(sz[1]^sz[2]==k){
                cout<<1;
            }cout<<0;
        }return 0;
    }if(n==1){
        if(sz[1]==k){
            cout<<1;
        }else{
            cout<<0;
        }return 0;
    }
    if(pd2==1||pd1==1){
        if(k!=0&&k!=1){
            cout<<0;
        }
    }else{
        cout<<0;
    }return 0;
}