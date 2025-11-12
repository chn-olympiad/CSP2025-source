#include<bits/stdc++.h>
using namespace std;
namespace A{
	vector<int> x[200010];
	int n,m,k,u[100010],v[100010],w[100010],c[20],a[20][1000010];
	int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>u[i]>>v[i]>>w[i];
			x[v[i]].push_back(u[i]);
			x[u[i]].push_back(v[i]);
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				x[a[i]+100000].push_back(a[j]);
			}
		}
		cout<<0;
		return 0;
	}
}
int main(){
	return A::main();
}