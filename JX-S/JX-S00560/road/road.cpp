#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    int u,v;
    ll w;
};
vector<Node> a;
bool cmp(Node x,Node y){
    return x.w<y.w;
}
ll b[10][10100];
ll c[20];
int fa[10100];
int qry(int p){
    if (fa[p]==p) return p;
    else return fa[p]=qry(fa[p]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    ll sum=0;
    for (int i=1;i<=m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        a.push_back({u,v,w});
        sum+=w;
    }
    bool flagA=1;
    for (int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        if (c[i]>0) flagA=0;
        for (int j=1;j<=n;j++){
            scanf("%lld",&b[i][j]);
        }
    }
    if (flagA){
        for (int i=1;i<=k;i++){
            for (int j=1;j<=n;j++){
                a.push_back({n+i,j,b[i][j]});
            }
        }
        n+=k;
        sort(a.begin(),a.end(),cmp);
        for (int i=1;i<=n;i++) fa[i]=i;
        ll ans=0;
        for (auto i : a){
            int u=i.u,v=i.v;
            ll w=i.w;
            int fu=qry(u),fv=qry(v);
            if (fu == fv) continue;
            fa[fu]=fv;
            ans+=w;
        }
        printf("%lld\n",ans);
    }
    else printf("%lld\n",sum);
    return 0;
}
