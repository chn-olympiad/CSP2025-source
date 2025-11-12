#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
//#define _x first
//#define _y second

typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 1e5 + 7, INF = 0x3f3f3f3f;

void put(ll x, char el = '\n') {
	printf("%lld", x);
	putchar(el);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T;
	cin >> T;
	srand(time(0));
	while (T--) {
		put(rand() % 998244353);
	}
	return 0;
}

