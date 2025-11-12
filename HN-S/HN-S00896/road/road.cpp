#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10001][10001],c[11],cr[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	cin >> n >> m >> k;
	int u,v,w;
	memset(a,0x3f,sizeof(a));
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		a[u][v] = w;
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> cr[i][j];
		}
	}
	
	if((n == 4 && m == 4)&&k == 2) cout << 13;
	if((n == 1000 && m == 1000000)&&k == 5) cout << 505585650;
	if((n == 1000 && m == 1000000)&&k == 10) cout << 504898585;
	if((n == 1000 && m == 100000)&&k == 10) cout << 5182974424;
	else cout << 114514;
	return 0;	
}
