#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
#define pp pop_back
//#define _x first
//#define _y second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e2 + 7, INF = 0x3f3f3f3f;

void put(ll x, char el = '\n') {
	prt("%lld", x);
	putchar(el);
}

int a[N];
int tot = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		scanf("%d", &a[++tot]);
	} 
	k = a[1];
	sort(a+1, a+n*m+1, greater<int>());
	int p = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			p = i;
			break;
		}
	}
	int x = ceil(1.0 * p / m), y = p%m;
	if (y == 0) y = m;
	p = x;
	int q;
	if (p & 1) q = y;
	else q = m - y + 1;
	prt("%d %d\n", p, q);
//	fclose(stdin); fclose (stdout);
	return 0;
}

