#include<bits/stdc++.h>
#define int64 long long
using namespace std;
const int N = (int)1e5 + 5;
const int INF = (int)1e9;

int T, n, a1[N], a2[N], a3[N], ans;
int cnt1 = 0, cnt2 = 0, cnt3 = 0;

void dfs(int temp, int tim, int state) {
//	if (temp > ans)	return;
	if (tim >= n + 1 || cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) {
		printf("%d\n", ans);
		ans = max(ans, temp);
		return;
	}
	
	if (state == 1)	temp += a1[tim], cnt1++;
	if (state == 2)	temp += a2[tim], cnt2++;
	if (state == 3)	temp += a3[tim], cnt3++;
	
	dfs(temp, tim + 1, 1);
	dfs(temp, tim + 1, 2);
	dfs(temp, tim + 1, 3);
	return;
}

void solve1() {
	int res = 0;
	for (int i = 1; i <= n / 2; i++)	res += a1[i];
	printf("%d\n", res);
}

void read() {
	scanf("%d", &n);
	
	bool pd = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
		if (a2[i] != 0 || a3[i] != 0)	pd = false;
	} 
	if (pd)	solve1();
	else {
		ans = 0;
		cnt1 = 0, cnt2 = 0, cnt3 = 0;
		dfs(0, 1, 0);
		printf("%d\n", ans);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	
	while (T--)	read();
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

