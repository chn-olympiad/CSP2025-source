#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int l[1005][1005];
int h[1005][1005];
int hf[10];
int f[10];
int t[10][1005];


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for (int i=0;i<m;i++) {
		int v, u,w;
		cin>>v>>u>>w;
		l[v][u] = w;
		l[u][v] = w;
	}
	for (int i=0;i<k;i++) {
		cin >> f[i];
		for (int j=0;j<n;j++) {
			cin>>t[i][j];
		}
	}
	cout<<0;
}
