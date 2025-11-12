#include<bits/stdc++.h>
using namespace std;
int a[1145][1145],g[114];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum=0;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i==j)a[i][j]=0;
			else a[i][j]=114514;
		}
	   for(int i=1;i<=m;i++){
		int u,v,ve;
		cin>>u>>v>>ve;
		a[u][v]=ve;
		a[v][u]=ve;
	   }
	   for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][l]+a[l][j],a[i][j]);
			}
		int jz;
		for(int i=1;i<=k;i++){
			cin>>jz;
			sum+=jz;
			for(int i=1;i<=n;i++)cin>>g[i];
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(g[i]+g[j]!=0)a[i][j]=min(a[i][j],g[i]+g[j]);
			}
		for(int i=1,j=i+1;i<=m;i++,j++){
			cout<<a[i][j]<<" ";sum+=a[i][j];sum+=a[i][j];
		}
		cout<<sum;
	return 0;
}
