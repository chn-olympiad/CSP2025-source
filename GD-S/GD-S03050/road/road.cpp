#include <bits/stdc++.h>
using namespace std;

int n, m, k, u, v, w, tr[10011][10011], c[11], x, y, bi[10011], sum=1, mb, ans=0;
bool flag[11], vis[10011][10011];

void find() {
	int mi=1000000000, x1, y1;
	for (x1=0; x1<n+k; x1++) {
		for (y1=x1; y1<n+k; y1++) {
			int bian=0;
			if (x1>=n && !flag[x1-n]) bian=c[x1-n];
			if (y1>=n && !flag[y1-n]) bian+=c[y1-n];
			
			if (!vis[x1][y1] && bi[x1] != bi[y1]) {
				if (tr[x1][y1]+bian<mi) {
					mi=tr[x1][y1]+bian;
					
					x=x1;
					y=y1;
				}
			}
		}
	}
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	for (int i=0; i<10011; i++) {
		for (int j=0; j<10011; j++) {
			tr[i][j]=1000000000;
		}
	}

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		cin >> u >> v >> w;
		tr[v-1][u-1]=w;
		tr[u-1][v-1]=w;
	}
	
	for (int i=0; i<k; i++) {
		cin >> c[i];
		for (int j=0; j<n; j++) {
			cin >> w;
			tr[j][n+i]=w;
			tr[n+i][j]=w;
		}
	}
	
	// ‰»Î
	mb=n;
	for (int i=0; i<10011; i++) bi[i]=i;
	while (sum!=mb) {
		find();
		vis[x][y]=1;
		bi[x] = min(bi[x], bi[y]);
		bi[y] = bi[x];
		
		ans+=tr[x][y];
		
		if (x>=n && !flag[x-n]) {
			flag[x-n]=1;
			ans+=c[x-n];
			mb++;
		}
		if (y>=n && !flag[y-n]) {
			flag[y-n]=1;
			ans+=c[y-n];
			mb++;
		}
	}
	cout << ans;

	return 0;
}
