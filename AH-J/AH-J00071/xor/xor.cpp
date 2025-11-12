#include<bits/stdc++.h>
using namespace std;
long long n,a[500006],k,cnt1,cnt0,lx;
bool xza,xzb;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
            lx++;
        }
        else{
            cnt0+=lx/2;
            lx=0;
        }
        if(a[i]==0){
            cnt0++;
        }
        if(a[i]!=1){
            xza=1;
        }
        else if(a[i]!=1&&a[i]!=0){
            xzb=1;
        }
    }
    if(lx!=0){
        cnt0+=lx/2;
    }
    if(xza==0){
        if(k==1){
            cout<<n;
            return 0;
        }
        else if(k==0){
            cout<<n/2;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else if(xzb==0){
        if(k!=1&&k!=0){
            cout<<0;
            return 0;
        }
        else if(k==1){
            cout<<cnt1;
            return 0;
        }
        else if(k==0){
            cout<<cnt0;
            return 0;
        }
    }
    return 0;
}
