#include <bits/stdc++.h>

using namespace std;
struct edge {
    int to,weigh;
    edge(int x,int y) {to=x,weigh=y;}
};
struct ee {
    int a,b,weigh;
    bool operator< (ee b) {
        return weigh<b.weigh;
    }
    ee(int x,int y,int z){a=x,b=y,weigh=z;}
};
int fa[10010],rk[10010];
int getfa(int a) {
    if (fa[a]==a) return a;
    return fa[a]=getfa(fa[a]);
}
void Merge(int a,int b) {
    int faa=getfa(a),fab=getfa(b);
    if (faa==fab) return;
    if (rk[faa]<rk[fab]) {
        fa[faa]=fab,rk[fab]+=rk[faa];
    }else{
        fa[fab]=faa,rk[faa]+=rk[fab];
    }
}
int val[15];
vector<int> reb[15];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) {
        fa[i]=i,rk[i]=1;
    }
    vector<ee> es;
    for (int i=1;i<=m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        es.emplace_back(a,b,c);
        es.emplace_back(b,a,c);
    }
    for (int i=1;i<=k;i++) {
        cin >> val[i];
        int a;
        for (int j=1;j<=n;j++) {
            cin >>a;
            reb[i].push_back(a);
        }
        for (int j=1;j<=n;j++) if (reb[i][j-1]==0) for (int k=1;k<=n;k++) if (k!=j) es.emplace_back(j,k,reb[i][k-1]),es.emplace_back(k,j,reb[i][k-1]);
    }
    sort(es.begin(),es.end());
    int cnt=0;
    long long ans=0;
    for (int i=0;i<es.size();i++) {
        if (cnt==n) break;
        if (getfa(es[i].a)!=getfa(es[i].b)) {
            Merge(es[i].a,es[i].b),ans+=es[i].weigh;
        }
    }
    cout << ans;
    return 0;
}
