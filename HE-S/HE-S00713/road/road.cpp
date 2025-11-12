#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int a[N][N],b[N][N];
long long c[N],ans,d[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,jg;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>jg;
		a[u][v]=jg;
		a[v][u]=jg;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];b[j][i]=b[i][j];
		}
	}
	for(int j=1;j<=n;j++){
		d[j]+=b[j][0];
		for(int i=1;i<=n;i++){
			c[j]+=a[j][i];
			d[j]+=b[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]<c[i])ans-=c[i];ans+=d[i];
	}
	cout<<ans;
	return 0;
}
