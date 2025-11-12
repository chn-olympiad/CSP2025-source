#include<bits/stdc++.h>
using namespace std;
int n,m,k,xxx;
int s = 0;
long long ans = 0;
int fa[10010];
long long vil[10010];
int find(int so){
    if (fa[so]!=so){
        return find(fa[so]);
    }
    return so;
}
struct edge{
    long long u,v,w;
}e[2000010];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        fa[i] = i;
    }
    for (int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    for (int j=1;j<=k;j++){
        scanf("%d",&xxx);
        for (int i=1;i<=n;i++){
            scanf("%lld",&vil[i]);
            if (vil[i]==0) xxx = i;
        }
        for (int i=1;i<=n;i++){
            e[m+n*j-n+i].u = i;
            e[m+n*j-n+i].v = xxx;
            e[m+n*j-n+i].w = vil[i];
        }
    }

    sort(e+1,e+m+n*k+1,cmp);
    for (int i=1;i<=m+n*k;i++){
        if (find(e[i].u)!=find(e[i].v)){
            fa[find(e[i].u)] = e[i].v;
            ans += e[i].w;
            s++;
        }
        if (s>=n-1) break;
    }
    cout<<ans;
    return 0;
}
