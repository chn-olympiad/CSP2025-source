#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)

int n, m;
int arr[128]; 
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	REP(i, 1, n * m) scanf("%d", &arr[i]);
	
	int cScore = arr[1], cPos = 0;
	sort(arr + 1, arr + n * m + 1, greater<int>());
	REP(i, 1, n * m) if (arr[i] == cScore) {cPos = i; break;}
	
	int c = 1, r = 1; // 列, 行 
	REP(i, 1, cPos - 1) {
		if ((c % 2 == 1 && r == n) || (c % 2 == 0 && r == 1))
			c++; // 改变列号
		else if (c % 2 == 1) r++;
		else r--;
	}
	printf("%d %d", c, r);
	return 0;
}
