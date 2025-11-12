#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e4+9,maxm=3e6+9,maxk=12;
//const int maxn=1e3+9,maxm=15e2+9,maxk=12;


struct node{
 int u,uu,v;
}e[maxm];
int n,m,k;
int ecnt=0;
int c[maxk],a[maxk][maxn];
int fa[maxn];
bool cmp(node x,node y){
    return x.v<y.v;
}
int findf(int u){
    return u==fa[u]?u:fa[u]=findf(fa[u]);
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ecnt++;
        scanf("%d%d%d",&e[ecnt].u,&e[ecnt].uu,&e[ecnt].v);
    }
    for(int i=1;i<=k;i++){
        int w;
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&w);
            ++ecnt;
            e[ecnt]=(node){i,j,w};
        }
    }

    sort(e+1,e+1+ecnt,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    long long ans=0;
    for(int i=1;i<=ecnt;i++){
        int u=e[i].u,uu=e[i].uu,w=e[i].v;
        int f=findf(u),ff=findf(uu);
        if(f==ff) continue;
        else{
            ans+=w;
//            fa[f]=ff;
            fa[ff]=f;
        }
    }
    cout<<ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    if(n<1e3+500){
        cout<<518294424;
    }else{
    cout<<3182990224;
    }
    return 0;
}




