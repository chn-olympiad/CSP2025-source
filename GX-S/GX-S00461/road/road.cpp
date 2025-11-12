#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],v[11],fa[10001],flag[100001];
long long ans;
struct edge{
    int from,to,dis,i;
}a[1100001];
bool cmp(edge x,edge y){
    return x.dis<y.dis;
}
int find(int x){
    if(!fa[x])
        return x;
    return fa[x]=find(fa[x]);
}
long long calc(int e){
    int tot=0;
    long long sum=0;
    memset(fa,0,sizeof(fa));
    for(int i=1;tot<n+e-1 && i<=m+n*k;i++){
        if(a[i].i>m && !v[flag[a[i].i-m]]) continue;
        if(find(a[i].from)!=find(a[i].to)){
            fa[find(a[i].from)]=find(a[i].to);
            sum+=a[i].dis;
            tot++;
        }
    }
    return sum;
}
void dfs(int x,long long sum,int e){
    if(x>k){
        if(!ans)
            ans=sum+calc(e);
        else
            ans=min(ans,sum+calc(e));
        return;
    }
    dfs(x+1,sum,e);
    v[x]=1;
    dfs(x+1,sum+c[x],e+1);
    v[x]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].dis);
        a[i].i=i;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",c+i);
        for(int j=1,t;j<=n;j++){
            t=(i-1)*n+m+j;
            scanf("%d",&a[t].dis);
            a[t].from=n+i;
            a[t].to=j;
            flag[t-m]=i;
            a[t].i=t;
        }
    }
    sort(a+1,a+m+k*n+1,cmp);
    dfs(1,0,0);
    printf("%lld",ans);
    return 0;
}
