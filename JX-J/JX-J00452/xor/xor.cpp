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
    while (ch<'0' or ch>'9') {if (ch=='-')  f=-f;ch=getchar();}
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
int n,k,a[500005],s[500005],f[500005],maxx[500005];
unordered_map<int,int> cnt;
void solve(){
    n=read(),k=read();
    for (int i=1;i<=n;i++)
        a[i]=read(),s[i]=s[i-1]^a[i];
    int ans=0;
    cnt.clear();
    cnt[0]=0;
    for (int i=1;i<=n;i++){
        if (cnt.count(k^s[i]))
            f[i]=cnt[k^s[i]]+1;
        maxx[i]=max(maxx[i-1],f[i]);
        if (cnt.count(s[i]))
            cnt[s[i]]=max(cnt[s[i]],maxx[i]);
        else
            cnt[s[i]]=maxx[i];
    }
    for (int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    // for (int i=1;i<=n;i++)
    //     printf("%d ",f[i]);
    // printf("\n");
    printf("%d\n",ans);
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll t=1;
    // t=read();
    while (t--)
        solve();
    return 0;
}