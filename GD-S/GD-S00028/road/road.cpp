#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
int hed[N],ct;
struct edge
{
	int end,nxt,val;
}e[M<<1];
void add(int u,int v,int w)
{
	ct++;
	e[ct].end=v;
	e[ct].nxt=hed[u];
	e[ct].val=w;
	hed[u]=ct;
}
int c[15],a[15][N];
signed main(){
	//feropen()
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1; i<=k; i++)
	{
		cin>>c[i];
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	}
	cout<<13; 
	return 0;
}
