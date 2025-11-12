#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005],ans=0x3f3f3f3f,fa[10004],tot;
struct node{
    int s,t,d;
}w[1000005];
bool cmp(node a,node b){
    return a.d<b.d;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int check(int x){
    memset(fa,0,sizeof(fa));
    tot=0;
    node e[1000005];
    int aaa=c[x];
    for (int i=1;i<=n;i++){
        fa[i]=i;
    }
    for (int i=1;i<=m;i++){
        e[++tot]=((node){w[i].s,w[i].t,w[i].d});
    }
    for (int i=1;i<=n;i++){
        e[++tot]=((node){x,i,a[x][i]});
    }
    sort(e+1,e+tot+1,cmp);
    for (int i=1;i<=tot;i++){
        if (find(e[i].s)==find(e[i].t)) break;
        int ta=find(e[i].s),tb=find(e[i].t);
        fa[tb]=ta;
        aaa+=e[i].d;
    }
    return aaa;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> w[i].s >> w[i].t >> w[i].d;
    }
    for (int i=1;i<=k;i++){
        cin >> c[i];
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for (int i=1;i<=k;i++){
        ans=min(ans,check(i));
    }
    cout << ans;
    return 0;
}
