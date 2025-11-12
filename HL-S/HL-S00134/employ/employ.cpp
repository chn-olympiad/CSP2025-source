#include <cstdio>
#include <iostream>
using namespace std;

int place[505];
int ind[505];
int ddl[505];
const int mod = 998244353;
long long search(int i, int cnt) {
	if (i - 1 == 0) {
		if (cnt > 1) return 0;
		for (int j = 0; j < ddl[i]; j++) {
			if (ind[j] == 0) continue;
			ind[j]--;
			search(i - 1, )
		}
	}
	// luqv
	for (int j = 0; j < ddl[i]; j++) {
		if (ind[j] == 0) continue;
		ind[j]--;
		search(i - 1, )
	}
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0, j = 0; i < n; i++) {
		char c; cin >> c;
		if (c == '0') {
			ind[j] = place[j] - 1;
			j++;
		}
		else {
			place[j]++;
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", ddl + i);
		ddl[i]--;
	}
}
