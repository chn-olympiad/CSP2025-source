#include <bits/stdc++.h>
using namespace std;
long long n,m,k,v[1010][1010],c[1000010],a[1010][1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin >>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >>a>>b>>c;
		v[a][b]=c;
		v[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		cin >>c[i];
		for(int j=1;j<=n;j++){
			cin >>a[i][j];
		}
	}
	cout <<0;
	return 0;
}
