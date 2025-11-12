#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _ 10005
ll n,m,k,fa[_],ans,c[15],w[15][_],bj[_];
struct bb {
    ll x,y,z;
    bool operator < (const bb &k) const {return z<k.z;}
}bian[_*100],a[_*100],b[_];
ll read() {
    ll x=0;char op=getchar();
    while(op>'9'||op<'0') op=getchar();
    while(op<='9'&&op>='0') x=(x<<3)+(x<<1)+(op-48),op=getchar();
    return x;
}
ll find(ll x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(ll x) {
    if(x>k) {
        ll tot=n-1,sum=0,now=n,num=0;
        for(ll i=1;i<n;i++) a[i]=b[i];
        for(ll i=1;i<=k;i++) {
            if(!bj[i]) continue;
            sum+=c[i],now++;
            for(ll j=1;j<=n;j++) a[++tot]={now,j,w[i][j]};
        }
        sort(a+1,a+tot+1);
        for(ll i=1;i<=now;i++) fa[i]=i;
        for(ll i=1;i<=tot;i++) {
            ll x=find(a[i].x),y=find(a[i].y);
            if(x==y) continue;
            sum+=a[i].z;
            fa[x]=y,num++;
            if(num==now-1) break;
        }
        ans=min(ans,sum);
        return ;
    }
    bj[x]=1;
    dfs(x+1);
    bj[x]=0;
    dfs(x+1);
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // double t=clock()*1.0;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++) fa[i]=i;
    for(ll i=1;i<=m;i++) cin>>bian[i].x>>bian[i].y>>bian[i].z;
    for(ll i=1;i<=k;i++) {
        cin>>c[i];
        for(ll j=1;j<=n;j++) cin>>w[i][j];
    }
    // cerr<<(clock()*1.0-t*1.0)/CLOCKS_PER_SEC<<'\n';
    sort(bian+1,bian+m+1);
    // cerr<<(clock()*1.0-t*1.0)/CLOCKS_PER_SEC<<'\n';
    ll tot=0;
    for(ll i=1;i<=m;i++) {
        ll x=find(bian[i].x),y=find(bian[i].y);
        if(x==y) continue;
        fa[x]=y;
        b[++tot]=bian[i];
        ans+=bian[i].z;
        if(tot==n-1) break;
    }
    dfs(1);
    cout<<ans;
    // cerr<<(clock()*1.0-t*1.0)/CLOCKS_PER_SEC;
    return 0;
}