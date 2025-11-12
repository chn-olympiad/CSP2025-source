#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+5],v[m+5],c[k][n+5],a[m+5],ans=0;
	long long w[m+5];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
	for(int j=1;j<=n+1;j++){
		cin>>c[i][j];
	}
	 }
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(w[i]>w[j]){
				swap(w[i],w[j]);
				swap(u[i],u[j]);
				swap(v[i],v[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[v[i]]!=1||a[u[i]]!=1){
			a[u[i]]=1;
			a[v[i]]=1;
			ans+=w[i];
		}
		
	}
	cout<<ans; 
	return 0;
	}
