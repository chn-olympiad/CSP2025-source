#include <bits/stdc++.h>
#define MAXN 503
#define mod 998244353
using namespace std;
int n,m;
int s[MAXN],c[MAXN];
int main(){
    // freopen("employ3.in","r",stdin);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    string s; cin>>s;
    int cntz=0;
    for (int i=1;i<=n;i++){
        cin>>c[i]; if (c[i]==0) cntz++;
    }
    if (cntz<=n-m){
        long long ans=1;
        for (int i=1;i<=n;i++) ans=1ll*ans*i%mod;
        cout<<ans<<'\n';
    } else {
        cout<<0<<'\n';
    }
    return 0;
}