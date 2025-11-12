#include <bits/stdc++.h> 
using namespace std;
int n,m,k,u[100005],v[100005],w[100005],a[10005][1001],sum;


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;i<=n+1;i++){
		cin>>a[i][k];
	}
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=n;i++){
		sum=w[i]+sum;
	}
	cout<<sum;
	return 0;
} 
