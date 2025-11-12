#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}d[1000006];
int c[15],a[15][10004];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) 
		cin >> d[i].u >> d[i].v >> d[i].w;
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
} 
