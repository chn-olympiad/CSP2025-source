#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010];
long long f[10010],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long w=1;
    for(int i=0;i<=a[n];i++)f[i]=1;
    for(int i=1;i<=n;i++,w=w*2%mod){
        (ans+=w-f[a[i]]+mod)%=mod;
        for(int j=a[n];j>=a[i];j--)
            (f[j]+=f[j-a[i]])%=mod;
    }
    cout<<ans<<'\n';
    return 0;
}