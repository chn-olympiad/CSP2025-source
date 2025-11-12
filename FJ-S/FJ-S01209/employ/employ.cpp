#include <bits/stdc++.h>
#define N 501
using namespace std;

int n, m;
string s;
int c[N];
int ans = 0;

void dfs(int pos, int pass, int ac) {
	if (pos == n + 1) {
		
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	cin >> s;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	
	dfs(1, 0, 0);
	
	return 0;
}