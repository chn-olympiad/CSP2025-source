#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct edge{
	int u,v,w;
}g[N];
bool cmp(edge a,edge b){
	return a.w<b.w; 
}
int n,m,k,a[15][N],f[N],ans,ans2,q[15],c[15],cnt;
int fd(int x){
	if(f[x]==x)return x;
	return (f[x]=fd(f[x]));
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			g[++m]={n+i,j,a[i][j]};
		}
	}
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=n+k;i++)f[i]=i;
	cnt=0;
	for(int i=1;i<=m;i++){
		int u=fd(g[i].u);
		int v=fd(g[i].v);
		if(u==v)continue;
		ans2+=g[i].w;cnt++;if(cnt==n+k-1)break;
		f[u]=v;
	}
	cout<<ans2;
	return 0;
}
