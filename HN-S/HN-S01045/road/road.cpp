#include<bits/stdc++.h>
using namespace std;
int u[10005],v[10005],w[10005];
int c[10005];
int a[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=n;++i){
		cin>>c[i];
		for(int j=1;j<=m;++j)
			cin>>a[j];
	}
	return 0;
}
