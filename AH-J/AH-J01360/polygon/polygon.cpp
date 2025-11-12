#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans;
long long f(long long N,long long M){
    long long res=1;
    for(long long i=1;i<=M;i++)
        res=res*(N-i+1)/i%998244353;
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
    }
    else
    {
        for(long long i=3;i<=n;i++)
            ans=(ans+f(n,i))%998244353;
        cout<<ans;
    }
    return 0;
}
