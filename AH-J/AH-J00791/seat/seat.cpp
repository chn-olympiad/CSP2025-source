#include<bits/stdc++.h>
using namespace std;

const int MAXN = 15;

int n, m;
int sum;
int goal;
int sco[MAXN * MAXN];
int vis[MAXN][MAXN];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	sum = n * m;
	for (int i = 1; i <= sum; ++i) scanf("%d", &sco[i]);
	
	goal = sco[1];
	sort(sco + 1, sco + sum + 1);
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) vis[i][j] = 1;
	
	int row = 0, colu = 1;
	for (int i = sum; i; --i) {
		
		if ( vis[row + 1][colu] ) ++row;
		else if ( vis[row - 1][colu] ) --row;
		else ++colu;
		
		vis[row][colu] = 0;
		if (sco[i] == goal) break;
	}
	cout << colu << " " << row << endl;
	
	return 0;
}
