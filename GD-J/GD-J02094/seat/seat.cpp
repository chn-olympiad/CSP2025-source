#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1145],cur = 0;
map <int,int> toid;
map <int,int> tonum;

bool cmp(int x,int y) {
	return x > y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int t = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1; i <= n * m; i++) {
		if (toid[a[i]] == 0) {
			toid[a[i]] = ++cur;
			tonum[cur] = a[i];
		}
	}
	t = toid[t];
	if (t % n == 0) {
		if ((t / n) % 2 == 1) {
			cout << (t / n) << " " << n; 
		} else {
			cout << (t / n) << " " << 1;
		}
	} else {
		if ((t / n) % 2 == 1) {
			cout << (t / n + 1) << " " << n + 1 - t % n;
		} else {
			cout << (t / n + 1) << " " << t % n;
		}
		
	}
	return 0;
}
