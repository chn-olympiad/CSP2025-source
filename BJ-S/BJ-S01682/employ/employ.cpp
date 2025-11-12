#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
constexpr int N=505,mod=998244353;
typedef long long ll;
inline ll qpow(ll a,ll b){ll c=1;while(b){if(b&1)c=c*a%mod;a=a*a%mod;b>>=1;}return c;}
int n,m,c[N],p[N];
string s;
int a[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s='$'+s;
    rep(i,1,n)cin>>c[i];
    if(n<=10){
        iota(a+1,a+1+n,1);
        ll ans=0;
        do{
            int fail=0;
            rep(i,1,n){
                if(s[i]=='0'||fail>=c[a[i]]){
                    fail++;
                }
            }
            if(fail<=n-m)ans++;
        }while(next_permutation(a+1,a+1+n));
        cout<<ans;
        return 0;
    }
    if(m==n){
        int cnt=0;
        rep(i,1,n)if(c[i]==0)cnt++;
        if(cnt)return cout<<0,0;
        cnt=0;
        rep(i,1,n)if(s[i]=='0')cnt++;
        if(cnt)return cout<<0,0;
        ll ans=1;
        rep(i,1,n)ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    return 0;
}