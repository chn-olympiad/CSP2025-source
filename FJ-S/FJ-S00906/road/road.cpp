#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005],n,m,k,v,u,c[100],w[1005],sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v>>u;
		cin>>a[min(v,u)][max(v,u)];
		sum+=a[min(v,u)][max(v,u)];
	} 
	for(int i=1;i<=k;i++){
		bool flag[i]=1;
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	cout<<sum;
	return 0; 
}
