#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5010]={0},f=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)f=0;
    }
    if(n<=3){
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])cout<<1;
        else cout<<0;
        return 0;
    }
    if(f){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=mod;
        }
        int d=n*(n-1)/2;
        d%=mod;
        if(ans-1-n-d<0){
            cout<<(ans-1-n-d+mod);
        }
        else cout<<(ans-1-n-d);
    }
    return 0;
}
