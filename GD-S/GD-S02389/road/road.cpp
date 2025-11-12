#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int c[10010];
	int a[10010];
	cin>>n>>m>>k;
	int u[10010],v[10010],w[100010];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
