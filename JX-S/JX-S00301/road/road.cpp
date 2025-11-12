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
int n,m,k,c[15][10005],fa[10005];
struct node{
    int u,v,c;
}b[10005];
// vector<pair<int,int> > a;
bool cmp(node x,node y){
    return x.c<y.c;
}
int find(int x){
    if (fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
ll F(){
    sort(b+1,b+m+1,cmp);
    for (int i=1;i<=n;i++)
        fa[i]=i;
    ll ans=0;
    for (int i=1;i<=m;i++){
        int u=b[i].u,v=b[i].v,c=b[i].c;
        u=find(u),v=find(v);
        if (u==v)
            continue;
        ans+=c;
        fa[u]=v;
    }
    return ans;
}
void solve(){
    n=read(),m=read(),k=read();
    for (int i=1;i<=m;i++){
        int u=read(),v=read(),c=read();
        // a[u].push_back({v,c});
        // a[v].push_back({u,c});
        b[i]={u,v,c};
    }
    // for (int i=1;i<=k;i++){
    //     for (int j=0;j<=n;j++)
    //         c[i][j]=read();
    // }
    printf("%lld\n",F());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll t=1;
    // t=read();
    while (t--)
        solve();
    return 0;
}