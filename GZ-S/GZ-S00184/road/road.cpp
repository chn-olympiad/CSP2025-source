//GZ-S00184 赫章新纪元学校 彭奥博
#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+5,maxn=1e4+5;
int u[maxm],v[maxm],w[maxm];
int head[maxm],next[maxm];
int edgenum;
int c[15],a[15][maxn];
int n,m,k;
void addedge(int a,int b,int c){
	u[++edgenum]=a;
	v[edgenum]=b;
	w[edgenum]=c;
	next[edgenum]=head[u[edgenum]];
	head[u[edgenum]]=u[edgenum];
}
int p[maxn];
int find(int u){
	return p[u]==u?u:p[u]=find(p[u]);
}
int solve(){
	int ans=0;
	for(int i=0;i<=n;i++)p[i]=i;
	for(int i=1;i<=edgenum;i++){
		int x=find(u[i]),y=find(v[i]);
		if(x!=y){
			ans+=w[i];
			p[x]=y;
		}
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;i<=n;i++)cin>>a[i][j];
	}
	cout<<solve();
	return 0;
} 
