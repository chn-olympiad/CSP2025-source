#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
#define pow po_w
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9'){ if (ch=='-')f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll po_w(ll x,ll y,ll mod){
    ll ans=1;
    while (y){
        if (y&1)
            ans*=x;
        x*=x;
        y>>=1;
        x%=mod;
        ans%=mod;
    }
    return ans;
}
ll gcd(ll x,ll y){
    if (y==0)
        return x;
    return gcd(y,x%y);
}
int n,q,cnt[200005],id1[200005],di2[200005];
string s1[200005],s2[200005];
void solve(){
    // n=read(),q=read();
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    for (int i=1;i<=n;i++){
        cnt[i]=s2.length()-s1.length();
        for (int j=0;j<s1.length();j++)
            if (s1[i]=='b')
                id1[i]=j;
        for (int j=0;j<s2.length();j++)
            if (s2[i]=='b')
                id2[i]=j;
    }
    while (q--){
        string t1,t2;
        cin>>t1>>t2;
        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll t=1;
    // t=read();
    while (t--)
        solve();
    return 0;
}