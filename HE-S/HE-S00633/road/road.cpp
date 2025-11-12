#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxm 1000005
#define maxn 10005
ll n,m,k,top=1,ans=0;
ll fa[maxn],a[maxn];
void build(){
    for (int i=0;i<maxn;i++){
        fa[i]=i;
    }
}
int Find(int x){
    if (fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void add(int x,int y){
    fa[fa[x]]=y;
}
bool query(int x,int y){
    if (Find(x)==Find(y))return true;
    return false;
}
struct Edge{
    ll u,v,w;
    Edge():u(u),v(v),w(w){}
};
bool cmp(Edge A,Edge B){
    return A.w<B.w;
}
Edge G[maxm];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if (k==0){
        build();
        for (int i=1;i<=m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            Edge E;
            E.u=u;E.v=v;E.w=w;
            G[top++]=E;
        }
        sort(G+1,G+m+1,cmp);
        for (int i=1;i<=m;i++){
            if (!query(G[i].u,G[i].v)){
                    add(G[i].v,G[i].u);
                ans+=G[i].w;
            }
        }
        cout<<ans<<endl;
    }else {
        build();
        for (int i=1;i<=m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            Edge E;
            E.u=u;E.v=v;E.w=w;
            G[top++]=E;
        }
        for (int i=1;i<=k;i++){
            ll o;
            cin>>o;
            for (int i=1;i<=n;i++){
                cin>>a[i];
                if (a[i]==0){
                    for (int j=1;j<i;j++){
                        Edge E;
                        E.u=j;E.v=i;E.w=o+a[j];
                        G[top++]=E;
                    }
                }
            }
        }
        sort(G+1,G+m+1,cmp);
        for (int i=1;i<=m;i++){
            if (!query(G[i].u,G[i].v)){
                    add(G[i].v,G[i].u);
                ans+=G[i].w;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
