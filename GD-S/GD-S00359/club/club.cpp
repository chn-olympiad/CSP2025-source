#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int m[1010][4];
int p;
int b[4][1010];

int solve(int a) {
	int MAXN = m[a][1];
	int bu = 1;
	for (int i = 1; i <= 3; i++) {
		if (m[a][i] > MAXN) {
			MAXN = m[a][i];
			int bu = i;
		}
	}
	int len = sizeof(b);
	p = p + MAXN;
	return p;
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	int ans = 0;
		
	for (int i = 1;i <= t; i++) {
		cin >> n;
		p = 0;
		for (int j = 1; j <= n; j++) {
			
			cin >> m[j][1] >> m[j][2] >> m[j][3];
				
			solve (j);
			
		}
		cout << p << endl;
	}
	
		
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
