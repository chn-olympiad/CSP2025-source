#include<bits/stdc++.h>
#define N 10005
#define inf 0xfffffffffffffff
typedef long long ll;
using namespace std;//cengfen
int n,m,k;bool v[N]={};
ll p[N][N]={},c[20],a[20][N],d[N],w=0;
inline int find(){
	ll t=inf,id=1;
	for(int i=2;i<=n;i++)
		if(!v[i]&&d[i]<t)id=i,t=d[i];
	return id;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	v[0]=1;cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			p[i][j]=p[j][i]=inf;
	for(int i=0,u,v_;i<m;i++){
		cin>>u>>v_;cin>>p[u][v_];
		p[v_][u]=p[u][v_];
	}
	for(int i=1;i<=n;i++)d[i]=p[1][i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=1;i<n;i++){
		int t=find();
		w+=d[t],v[t]=1;
		for(int i=2;i<=n;i++)
			if(d[i]>p[t][i])d[i]=p[t][i];
	}
	cout<<w;
}
