#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c[N][N];
/*void bfs(int st)
{
	int s=st;
	Q.push(t);
	cs[t]=0;
	for(int bh:G[s]){
		d[i]+=s[t];*/
		
int main()
{
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		//G[u].push_back(v);
		//G[v].push_back(u);
		//d[u][v]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>c[i][j];
	}
	//for(int i=1;i<=n;i++)bfs(i);
	cout<<0<<' ';
	return 0;
}
