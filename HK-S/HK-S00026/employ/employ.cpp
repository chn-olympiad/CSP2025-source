#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod=998244353;

ll qpow(ll a, ll b){
    ll res=1;
    while (b>0){
        if (b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

ll n, m, a[505];
string s;

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    
    bool flag=true;
    cin>>n>>m;
    cin>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
    s=" "+s;

    for (int i=1;i<=n;i++) if (s[i]=='0') flag=false;

    if (m==n){
        for (int i=1;i<=n;i++){
            if (s[i]=='0'){
                cout<<0<<endl;
                return 0;
            }

            if (a[i]==0){
                cout<<0<<endl;
                return 0;
            }
        }
    }

    if (m==1 || flag){
        ll ans=0;
        for (int i=1;i<=n;i++) ans=ans*i%mod;

        cout<<ans<<endl;
        return 0;
    }
    
    return 0;

    fclose(stdin);
    fclose(stdout);
}