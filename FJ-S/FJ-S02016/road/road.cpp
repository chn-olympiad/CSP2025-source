#include<bits/stdc++.h>
#define ll long long
#define MAXN (int)1e4+5
#define MAXM (int)1e6+5
#define MAXK 15
using namespace std;
struct Edge{
	int u,v,w;
}nowE;
bool operator<(Edge a,Edge b){
	return a.w<b.w;
}
int n,m,k,u,v,w,sumw;
int rc[MAXN],c[MAXK];
int a[MAXK][MAXN];
vector<Edge>Adj;
priority_queue<Edge>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(rc,0,sizeof(rc));
	sumw=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>u>>v>>w,
		rc[u]++,rc[v]++,sumw+=w,
		Adj.push_back((Edge){u,v,w}),
		q.push(Adj[i-1]);
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	for(int i=1;i<=m-n+1;++i){
		FLAG:
		nowE=q.top();
		q.pop();
		if(rc[nowE.u]==1||rc[nowE.v]==1)goto FLAG;
		sumw-=nowE.w;
	}
	cout<<sumw;
	return 0;
}
/*

4 5 0
1 2 1
1 4 3
1 3 3
3 4 2
2 4 1

5 6 0
1 4 6
2 3 7
4 2 5
4 3 4
1 5 1
3 5 2

special1~4

*/
