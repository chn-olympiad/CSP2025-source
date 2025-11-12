#include <bits/stdc++.h>
using namespace std;
long long v[1e9],u[1e9],w[1e9];
long long c[1e9],a[1e9][1e9];
int main(){
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	int n,m,k,ans=0,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>u[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i]>>a[i][j];
		}
	}
	return 0;
}
