#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5,M=1e4+5,mod = 998244353;
typedef long long ll;
ll fac[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        if(u > 0) cnt ++;
    }
    fac[0] = 1;
    for(int i=1;i<=n;i++){
        fac[i] = (fac[i-1] * i) % mod;
    }
    ll tot = 1;
    // cout<<cnt<<' '<<m<<'\n';
    for(int i = cnt;i>cnt-m;i--){
        tot = (tot * i) % mod;
    }
    cout<<(tot * fac[n-m]) % mod;
    return 0;
}