#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=1,n;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=n;i>1;i--){
        ans*=i;
    }
    ans%=998244353;
    printf("%lld",ans);
    return 0;
}
