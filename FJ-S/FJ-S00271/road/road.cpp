#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10010];
int head[10010],ver[20010],ne[20010],wer[20010],tot;
int vis[10010];
void add(int u,int v,int w){
	tot++; ne[tot]=head[u]; ver[tot]=v; wer[tot]=w; head[u]=tot;
}
struct node{
	int x=1;
	long long money=0;
	bool b[2000010]={0};
}tmp;
queue<node> q;
void dfs(int x,int k){
	vis[x]=k;
	for(int i=head[x];i;i=ne[i]){
		if(!vis[ver[i]]&&tmp.b[i]) dfs(ver[i],k);
	}
	return ;
}
long long spfa(){
	q.push(tmp);
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		for(int i=1;i<=n;i++) vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				dfs(i,++cnt);
		if(cnt==1) return tmp.money;
		for(int i=head[tmp.x];i;i=ne[i]){
			int v=ver[i],w=wer[i]*tmp.b[i];
			if(vis[tmp.x]==vis[v]) continue;
			node mp=tmp;
			mp.x=v;
			mp.money+=w;
			mp.b[i]=mp.b[i+1]=1;
			q.push(mp);
		}
	}
	return -1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;k++){
			cin >> a[i][j];
		}
	}
	cout << spfa();
	return 0;
}
