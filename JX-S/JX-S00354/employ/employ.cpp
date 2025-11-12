#include<bits/stdc++.h>
#define ll long long
const int N=1e6+100;
const int mod=998244353;
using namespace std;
ll T,n,m,ans=0;
ll a[N];
string s;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    int t=n;
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        if(a[i]==0) t--;
    }
    ll ans=1;
    for(int i=2;i<=t;++i)
        ans=(ans*i)%mod;
    printf("%lld",ans);
    return 0;
}
