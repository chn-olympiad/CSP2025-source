#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,a[N][5],b[15][15],num=1,ans=0,t[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		cin >> a[i][1] << a[i][2] << a[i][3];
	}
	for (int j=1;j<=k;j++){
		for (int i=1;i<=n;i++){
			cin >> b[j][i];
		}
	}
	for (int i=1;i<=k;i++){
		for (int j=1;j<=n;j++){
			if (b[i][j]==0) 
		}
	}
	return 0;
}
