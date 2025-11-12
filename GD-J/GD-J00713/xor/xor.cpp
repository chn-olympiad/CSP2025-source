#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define FileIO(str) freopen(str".in", "r", stdin); freopen(str".out", "w", stdout)
void read(int *x) {
	int f = 1, ch = getchar();
	*x = 0;
	while (!isdigit(ch)) {
		if (ch == 45) {
			f = -f;
		}
		ch = getchar();
	}
	do {
		*x = (*x << 1) + (*x << 3) + (ch ^ 48);
		ch = getchar();
	} while(isdigit(ch));
}
void write(int x) {
	if (x < 0) {
		putchar(45);
		if (x == -2147483648ll) {
			putchar(50);
			x += 2000000000;
		}
		x = -x;
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + 48);
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int n, k, a[500001], cnt, lst = -1;
long long pref[500001];
vector<pair<int, int> > kk;
unordered_map<long long, int> vis;
unordered_map<int, int> ft;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	read(&n);
	read(&k);
	vis[0] = 0;
	for (int i = 1; i <= n; ++i) {
		read(&a[i]);
		pref[i] = pref[i - 1] ^ a[i];
		if (vis.count(k ^ pref[i])) {
			ft[vis[k ^ pref[i]]] = i;
			vis.erase(k ^ pref[i]);
		}
		vis[pref[i]] = i;
	}
	for (int l = 0; l <= n; ++l) {
		if (ft.count(l)) {
			kk.emplace_back(ft[l], l + 1);
		}
	}
	sort(kk.begin(), kk.end(), cmp);
	for (auto i : kk) {
		if (i.second > lst) {
			lst = i.first;
			++cnt;
		}
	}
	write(cnt);
}
