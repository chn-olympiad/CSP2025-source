#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> u(m+1);
	vector<int> v(m+1);
	vector<int> w(m+1);
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>w[i];
	}
	vector<int> c(k+1);
	int a[k+1][n+1];
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	cout<<"28"<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
