#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long c(long long x,long long y){
    long long sum1=1,sum2=1;
    for(long long i=x;i>=(x-y+1);i--){
        sum1=sum1*i%998244353;
    }
    for(long long i=y;i>=1;i--){
        sum2=sum2*i%998244353;
    }
    return (sum1/sum2);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    for(long long i=3;i<=n;i++){
        ans+=c(n,i);
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
