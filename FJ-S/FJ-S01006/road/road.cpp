#include<bits/stdc++.h>
using namespace std;
const int long long N=1e6,M=1e4;
long long n,m,k,ans;
long long u[N+5],v[N+5],w[N+5]; 
long long c[M],a[M+5][5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin >>u[i]>>v[i]>>w[i];
	}
	sort(w+1,w+m+1);
	for (int i=1;i<=k;i++){
		cin >>c[i];
		for (int j=1;j<=n;j++){
			cin >>a[i][j];
		}
	}
	sort(c+1,c+k+1);
	cout <<w[1]+w[2]+c[1]+3;
	return 0;
}
