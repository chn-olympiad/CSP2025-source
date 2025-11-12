#include <bits/stdc++.h>
using namespace std;

const int tt=1e6+10;
int u[tt],v[tt],w[tt];
int c[tt],a[tt];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++){
		cin >>u[i]>>v[i]>>w[i];
		cnt+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin >>c[i];
		for(int j=1;j<=n;j++){
			cin >>a[j];
		}
	}
	cout <<cnt;
	return 0;
}
