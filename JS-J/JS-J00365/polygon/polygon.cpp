#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int Mod=998244353;
typedef long long ll;
ll xj,Max,arr[N];
ll qpow(ll b,ll k){
    ll res=1;
    while(k>=1){
        if(k%2==1)res=res*b%Mod;
        k/=2;
        b=b*b%Mod;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>xj;
    for(ll i=1;i<=xj;i++){
        cin>>arr[i];
        Max=max(Max,arr[i]);
    }
    sort(arr+1,arr+1+xj);
    if(xj==3){
        if(arr[1]+arr[2]>arr[3])cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    else if(Max==1){
        cout<<1ll*qpow(2,xj)-1-xj-(xj-1)*xj/2;
    }
    return 0;
}
