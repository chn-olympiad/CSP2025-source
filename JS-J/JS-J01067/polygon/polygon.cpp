#include <bits/stdc++.h>
using namespace std;
const int N=5009,MOD=998244353;
long long n,a[N],sum[N],s[N*N],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=sum[i];j>=a[i];--j){
            s[j]=(s[j]+s[j-a[i]])%MOD;
            if(a[i]*2<j)ans=(ans+s[j-a[i]])%MOD;
        }
        for(int j=1;j<i;++j){
            s[a[j]+a[i]]=(s[a[j]+a[i]]+1)%MOD;
        }
    }
    cout<<ans;
    return 0;
}
