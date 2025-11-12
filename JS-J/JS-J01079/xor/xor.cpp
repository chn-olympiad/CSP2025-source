#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans=0;
vector<ll> sta;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    ll x;
    for(ll _=1;_<=n;_++){
        scanf("%lld",&x);
        if(x==k){
            ans++;
            sta.clear();
            continue;
        }
        ll m=x;
        sta.push_back(x);
        for(ll i=2;i<=sta.size();i++){
            m^=sta[sta.size()-i];
            if(m==k){
                ans++;
                sta.clear();
                break;
            }
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
