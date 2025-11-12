#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10,maxm=2e6+10,maxk=15;
int n,m,k,u,v,w,fa[maxn],ans=INT_MAX,c[maxk],a[maxk][maxn];
bool book[maxn];
struct node{
    int u,v,w;
}e[maxm],g[maxm];
bool cmp(node a,node b){
    return a.w<b.w;
}
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void kruskal(){
    int cnt=0,sum=0,ver=0,edge=0;
    for(int i=0;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        g[i]=e[i];
    for(int i=1;i<=k;i++)
        if(book[i]){
            fa[i+n]=0,sum+=c[i],cnt++;
            ver++;
            for(int j=1;j<=n;j++)
                edge++,g[m+edge]={i+n,j,a[i][j]};
        }
    if(ver)
        ver++;
    if(sum>ans)
        return;
    sort(g+1,g+1+m+edge,cmp);
    for(int i=1;i<=m+edge;i++){
        int u=getfa(g[i].u),v=getfa(g[i].v),w=g[i].w;
        if(u!=v){
            cnt++;
            fa[u]=v;
            sum+=w;
            if(cnt==n+ver)
                break;
        }
    }
    ans=min(ans,sum);
}
void dfs(int x){
    if(x==k+1){
        kruskal();
        return;
    }
    book[x]=true;
    dfs(x+1);
    book[x]=false;
    dfs(x+1);
}
void solveA(){
	int sum=0,cnt=0,edge=0;
	for(int i=0;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		g[++edge]={e[i].u,e[i].v,e[i].w};
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			g[++edge]={j,i+n,a[i][j]},g[++edge]={i+n,j,a[i][j]};
	sort(g+1,g+1+edge,cmp);
	for(int i=1;i<=edge;i++){
		int u=getfa(g[i].u),v=getfa(g[i].v),w=g[i].w;
		if(u!=v){
			cnt++;
			sum+=w;
			fa[u]=v;
			if(cnt==n+k)
				break;
		}
	}
	printf("%lld",sum);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    bool flag=true;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        flag&=(!c[i]);
        a[i][0]=c[i];
        for(int j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
    }
    if(flag){
		solveA();
		return 0;
	}
    dfs(1);
    printf("%lld",ans);
    return 0;
}
// wo hai shi men ban fa...
// zai jian
// gan xie wo zai nnsz yu dao de mei yi wei oiers pap
