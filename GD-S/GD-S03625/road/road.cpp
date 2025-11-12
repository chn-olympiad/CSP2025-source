#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=4e6+10,N=2e4+10;
int n,m,k,ans=1e18,cnt,h[N],vis[N],d[15],cst[15];
struct node{
	int y,c,nxt;
}e[M];
bool operator < (node x,node y){
	return x.c>y.c;
}
priority_queue<node> q;
void add(int u,int v,int c){
	++cnt;
	e[cnt].y=v;
	e[cnt].c=c;
	e[cnt].nxt=h[u];
	h[u]=cnt;
	return ;
}
void prim(int tot){
	for (int i=1;i<=n+k;i++) vis[i]=0;
	q.push({1,0,0});int t=0,res=0;
	while (t<n+tot){
		node x=q.top();
		q.pop();
		if (vis[x.y]) continue;
		vis[x.y]=1;res+=x.c;t++;
		for (int i=h[x.y];i;i=e[i].nxt){
			int y=e[i].y;
			int c=e[i].c;
			if (vis[y]||(y>n&&!d[y-n])) continue;
			q.push({y,c,0});
		}
	}
	while (!q.empty()) q.pop();
	for (int i=1;i<=k;i++) 
		if (d[i]) res+=cst[i];
	ans=min(ans,res);
	return ;
}
void dfs(int pos,int tot){
	if (pos>k){
		prim(tot);
		return ;
	}
	d[pos]=1;
	dfs(pos+1,tot+1);
	if (cst[pos]){
		d[pos]=0;
		dfs(pos+1,tot);
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf ("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int u,v,c;
		scanf ("%lld%lld%lld",&u,&v,&c);
		add(u,v,c);add(v,u,c);
	}
	for (int i=1;i<=k;i++){
		scanf ("%lld",&cst[i]);
		for (int j=1;j<=n;j++){
			int c;scanf ("%lld",&c);
			add(i+n,j,c);add(j,i+n,c);
		}
	}
	dfs(1,0);
	printf ("%lld",ans);	
	
	
	return 0;
}
/*
4 3 0
1 4 6
4 2 5
4 3 4
*/
