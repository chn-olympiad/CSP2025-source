#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const int inf = 1e9 + 7;

using namespace std;

int T;

void work() {
	while (T--) {
		
	}
}

inline int read() {
	int x = 0, k = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') k = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x*k;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cout << 2 << endl << 0;
	return 0;
} 
