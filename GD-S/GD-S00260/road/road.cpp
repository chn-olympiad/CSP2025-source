#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node{int v,w;};
int n,m,k,c[20],a[20][N];
int e[N][N],g[N][N],ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=1;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,e[u][v]=e[v][u]=w,ans+=w;
	for(int i=1;i<=k&&cin>>c[i];i++)
		for(int j=1;j<=n&&cin>>a[i][j];j++)
			if(!a[i][j]) 
				g[i][j]=g[j][i]=e[i][j];
	return cout<<ans,0; 
}
