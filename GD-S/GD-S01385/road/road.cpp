#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,l[5005][5005],maxn=-1e9,ans;
/*void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				l[i][j]=min(l[i][j],l[i][k]+l[k][j]);	
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(l,0x3f,sizeof(l));
	for(int i=1;i<=n;i++){
		l[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		l[u][v]=w;
		l[v][u]=w;
		ans+=w;
	}
	//庆祝一下约等于爆0 
	//floyd();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			maxn=max(maxn,l[i][j]);
		}
	cout<<ans-maxn;
	return 0;
}
