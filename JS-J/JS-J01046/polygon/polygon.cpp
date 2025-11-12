#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;

long long a[5010],n,ans;

long long fun(long long d,long long s,long long m,long long c){
    if(d==n){
        if(c<3){
            return 0;
        }
        return (s-m>m);
    }
    return (fun(d+1,s,m,c)+fun(d+1,s+a[d+1],max(m,a[d+1]),c+1))%mod;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        ans=(ans+fun(i,a[i],a[i],1))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
