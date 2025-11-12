#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=1e6+10;
int n,m,k,fa[N],cnt,cst,num[20],len[20],ans=1e18;
struct node{
	signed u,v,w;
}e[M],e1[N],E[12][N],ls[N],now[12][N],nxt[N];
inline int find(int x){
	int y=x;
	while(x^fa[x])
		x=fa[x];
	while(y^fa[y]){
		int &now=fa[y];
		y=now,now=x;
	}
	return x;
}
inline bool cmp(node p,node q){
	return p.w<q.w;
}
inline void dfs(int u){
	if(u>k){
		int sum=cst;
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		for(int i=1;i<=len[k];i++){
			int u=now[k][i].u,v=now[k][i].v;
			u=find(u),v=find(v);
			if(u!=v) fa[u]=v,sum+=now[k][i].w;
		}
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=len[u-1];i++)
		now[u][i]=now[u-1][i];
	len[u]=len[u-1];
	dfs(u+1);
	cst+=num[u];
	int p1=1,p2=1,le=0;
	while(1){
		while(p1<=len[u]&&now[u][p1].w<=E[u][p2].w)
			nxt[++le]=now[u][p1],p1++;
		while(p2<=n&&E[u][p2].w<=now[u][p1].w)
			nxt[++le]=E[u][p2],p2++;
		if(p1>len[u]||p2>n) break;
	}
	while(p1<=len[u])
		nxt[++le]=now[u][p1],p1++;
	while(p2<=n)
		nxt[++le]=E[u][p2],p2++;
	len[u]=le;
	for(int i=1;i<=len[u];i++)
		now[u][i]=nxt[i];
	dfs(u+1);
	cst-=num[u];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>num[i];
		for(int j=1;j<=n;j++){
			int x=0;
			cin>>x;
			ls[j]={n+i,j,x}; 
		}
		sort(ls+1,ls+n+1,cmp);
		for(int j=1;j<=n;j++)
			E[i][j]=ls[j];
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		u=find(u),v=find(v);
		if(u!=v) e1[++cnt]=e[i],fa[u]=v;
	}
	for(int i=1;i<n;i++)
		now[0][i]=e1[i],len[0]++;
	dfs(1);
	cout<<ans;
	return 0;
}
