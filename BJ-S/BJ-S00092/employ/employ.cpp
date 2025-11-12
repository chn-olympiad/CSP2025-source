#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N=505, mod=998244353;
ll n, m, a[N], c[N], t[N], ans=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        char ch;
        cin>>ch;
        a[i]=ch-'0';
    }
    for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(ll i=1;i<=n;i++) t[i]=i;
    do{
        ll res=0, cnt=0;
        for(ll i=1;i<=n;i++){
            if(a[i]==0||cnt>=c[t[i]]) cnt++;
            else res++;
        }
        if(res>=m) ans++;
    }while(next_permutation(t+1,t+n+1));
    return printf("%lld",ans)&0;
}