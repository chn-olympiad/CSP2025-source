#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,m,a[501],flag=1,flag0=1,res[501]={1},cntz,b[501],c[501];
string st;
bool of(){
    bool p=1;
    ll cnt=0;
    for (ll i=1;i<=n;i++){
        if (c[i]<=cnt || st[i-1]=='0'){
            cnt++;
        }
    }
    return n-m>=cnt;
}
ll cal(ll x,ll y){
    ll res=1,cnt=x;
    for (ll i=100;cnt;i--,cnt--){
        res*=i;
        res%=MOD;
    }
    for (ll i=1;i<=y-x;i++) res=res*i%MOD;
    return res;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>st;
    for (ll i=1;i<=500;i++) res[i]=res[i-1]*i%MOD;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        b[i]=i;
        if (a[i]==0) cntz++;
    }
    sort(a+1,a+n+1);
    if (m==n){
        if (cntz>0 || st.find("0")==string::npos) cout<<0;
        else cout<<res[n];
        return 0;
    }
    if (n-cntz<m){
        cout<<0;
        return 0;
    }
    if (st.find("0")==string::npos){
        cout<<res[n]%MOD<<'\n';
        return 0;
    }
    if (n<=10){
        ll cnt=0;
        for (ll i=1;i<=n;i++) c[i]=a[b[i]];
        if (of()) cnt++;
        while (next_permutation(b+1,b+n+1)){
            for (ll i=1;i<=n;i++) c[i]=a[b[i]];
            if (of()) cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
