#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN=5005;
const long long MODE=998244353;
int a[MAXN];
long long sum[MAXN];
long long ans=0;
long long js(int x){
    long long ans=1;
    for(int i=1;i<=x;i++) ans=ans*i;
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    if(a[n]<2){
        long long ans=0;
        for(int i=3;i<=n;i++){
            ans+=js(i)%MODE/js(n)/js(n-i);
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j]*2%MODE<(sum[j]-sum[i])%MODE) ans=(ans+j-i)%MODE;
        }
    }
    cout<<ans-1;
    return 0;
}
