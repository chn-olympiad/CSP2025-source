#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e4+10,M=1e6+10,K=15;
int n,m,k,ans=LONG_LONG_MAX,c[K],a[K][N],fa[N+K];
struct edge{
    int u,v,w;
    bool operator < (const edge &p) const {
        return w>p.w;
    }
}e[M];
priority_queue<edge> pq;
int find(int p) {
    if (fa[p]==p) return p;
    return fa[p]=find(fa[p]);
}
int maketr() {
    int ans=0,used=0;
    while (pq.size()&&used<n-1) {
        edge p=pq.top();
        pq.pop();
        int u=p.u,v=p.v,w=p.w;
        int fu=find(u),fv=find(v);
        if (fu==fv) continue;
        fa[fu]=fv;
        used++;
        ans+=w;
    }
    return ans;
}
bool chi[N];
void dfs(int p) {
    if (p==k+1) {
        int times=0,csum=0;
        while (pq.size()) pq.pop();
        for (int i=1;i<=m;i++) pq.push(e[i]);
        for (int i=1;i<=n;i++) fa[i]=i;
        for (int i=1;i<=k;i++) {
            if (!chi[i]) continue;
            // cout<<i<<" ";
            times++;
            fa[n+times]=n+times;
            csum+=c[i];
            for (int j=1;j<=n;j++) pq.push({j,n+times,a[i][j]});
        }
        int nowans=maketr()+csum;
        // cout<<"\n"<<nowans<<"\n";
        n+=times;
        ans=min(ans,nowans);
        n-=times;
        return;
    }
    dfs(p+1);
    chi[p]=1;
    dfs(p+1);
    chi[p]=0;
}
signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    Cios;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    int maxc=-1;
    for (int i=1;i<=k;i++) {
        cin>>c[i];
        maxc=max(maxc,c[i]);
        for (int j=1;j<=n;j++) cin>>a[i][j];
    }
    if (maxc==0) {
        for (int i=1;i<=n;i++) fa[i]=i;
        for (int i=1;i<=m;i++) pq.push(e[i]);
        for (int i=1;i<=k;i++) {
            for (int u=1;u<=n;u++) {
                for (int v=u+1;v<=n;v++) pq.push({u,v,a[i][u]+a[i][v]});
            }
        }
        cout<<maketr()<<endl;
        return 0;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
//g++ road.cpp -o road -O2 -std=c++14 -static
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/