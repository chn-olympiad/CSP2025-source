#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int cnt=0;
int cnt0=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==0) cnt0++;
        else if(a[i]==1) cnt++;
    }
    if(cnt==n&&k==0)cout<<n;
    else if(cnt+cnt0==n&&k==0){
        int k0=1,k1;
        for(int i=0;i<n;i++){
            k1=a[i];
            if(a[i+1]==k1){
                k0++;
            }
            else{
                ans=max(k0,ans);
                k1=1-k1;
                k0=1;
            }
        }
        cout<<ans;
    }
    else if(cnt+cnt0==n&&k==1){
        int k0=1,k1;
        for(int i=0;i<n;i++){
            k1=a[i];
            if(a[i+1]==1-k1){
                k0++;
                k1=1-k1;
            }
            else{
                ans=max(k0,ans);
                k0=1;
            }
        }
        cout<<ans;
    }
    else{
        bool f=1;
        for(int i=0;i<n;i++){
            if(a[i]!=k)f=0;
        }
        if(f==1){
            if(n%2==0)cout<<1;
            else cout<<n;
        }
        else cout<<2;
    }
    return 0;
}
