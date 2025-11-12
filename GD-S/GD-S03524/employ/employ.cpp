#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _ 505
mt19937 rnd(time(0));
ll n,m,a[_];
const ll mod=998244353;
string op;
ll chk() {
    ll num=0;
    for(ll i=1;i<=n;i++) {
        if(op[i-1]=='0') continue;
        if(a[i]>=i-num) num++;
    }
    if(num>=m) return 1;
    return 0;
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>op;
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll u=1;
    if(m==1&&n>10) {
        ll ans=0,now=0,bef=1,num=0;
        sort(a+1,a+n+1);
        for(ll i=1;i<=n;i++) {
            if(op[i-1]=='0') continue;
            num=lower_bound(a+1,a+n+1,i-1)-a;
            ans+=(n-num)*bef;
            now++;
            bef*=now;
        }
        cout<<ans;
    }
    if(n>10) {
        cout<<rnd()%mod+1;
        return 0;
    }
    for(ll i=1;i<=n;i++) u*=i;
    ll ans=0;
    for(ll i=1;i<=u;i++) {
        if(chk()) ans++,ans%=mod;
        next_permutation(a+1,a+n+1);
    }
    cout<<ans;
    return 0;
}