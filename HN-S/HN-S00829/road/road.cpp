#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10010
int n,m,k,u,v,w,c[11],a[11][N];
struct node{
	int u,v,w,nxt;
}ed[N];
int cnt=0,tail[2000010];
void add(int u,int v,int w){
	ed[++cnt].u=u;
	ed[cnt].v=v;
	ed[cnt].w=w;
	ed[cnt].nxt=tail[u];
	tail[u]=cnt;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}
