#include<bits/stdc++.h>
using namespace std;

int p[10020];
int u[10020];
int v[10020];
int pk[20];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> u[i] >> v[i] >> p[i];
	}
	
	for (int i = 0; i < k; i++) {
		cin >> pk[i];
		u[n + i] = n + i + 1;
		for (int j = 0; j < n; j++)  {	
			v[n + i] = j + 1;
			cin >> p[n + i];
		}	
	}
	
	vector<vector<int>> ljb(n + k, vector<int>(n + k, 0));
	vector<bool> vis(n + k, false);
	
	for (int i = 0; i < n + k; i++) {
		ljb[u[i] - 1][v[i] - 1] = p[i];
	}
	
	int sum = 0;
	for (int i = 0; i < n + k; i++) {
		int minp = 100001;
		int cnt = i;
		for (int j = 0; j < n+k; j++) {
			if (ljb[cnt][j] != 0 && ljb[cnt][j] < minp && !vis[cnt]) {
				minp = ljb[cnt][j];
				cnt = j;
			}
		}
		sum += ljb[i][cnt];
		vis[cnt] = true;
	}
	cout << sum;
	return 0; 
}
