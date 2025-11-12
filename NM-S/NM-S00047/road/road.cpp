#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n,m,k,f[N],cnt,c[16][N];
long long ans=1e18;
struct Node{
    int l,to,v;
}e[N],tmp[N];
bool cmp(Node x,Node y){
    return x.v<y.v;
}
int _find(int x){
    if(f[x]==x) return x;
    return f[x]=_find(f[x]);
}
void dfs(int x,int _last,long long les){
    if(x>k){
        for(int i=1;i<=n+k;i++) f[i]=i;
        for(int i=1;i<=cnt;i++) tmp[i]=e[i];
        sort(tmp+1,tmp+cnt+1,cmp);
        for(int i=1;i<=cnt;i++)
            if(_find(tmp[i].l)!=_find(tmp[i].to)){
                les+=tmp[i].v;
                f[_find(tmp[i].l)]=_find(tmp[i].to);
            }
        ans=min(ans,les);
        return ;
    }
    dfs(x+1,cnt,les);
    for(int i=1;i<=n;i++){
        e[++cnt].l=i,e[cnt].to=n+x,e[cnt].v=c[x][i];
    }
    dfs(x+1,cnt,les+c[x][0]);
    cnt=_last;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        e[++cnt].l=x,e[cnt].to=y,e[cnt].v=z;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i][0]);
        for(int j=1;j<=n;j++) scanf("%d",&c[i][j]);
    }
    dfs(1,m,0);
    printf("%lld",ans);
    return 0;
}
