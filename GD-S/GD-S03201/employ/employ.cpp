#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int rp[N];
int nx[N];
int p[N];

bool Process () {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt >= nx[p[i]]) {
			cnt++;
			continue;
		}
		
		if (rp[i] == 0)
			cnt++;
	}
	
	return n - cnt >= m;
}

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &rp[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nx[i]);
	}
	
	for (int i = 1; i <= n; i++)
		p[i] = i;
	
	int ans = 0;
	do {
		if (Process()) {
			ans++;
//			printf("This is OK. I will shou you.\n");
//			for (int i = 1; i <= n; i++) {
//				cout << p[i] << ' ';
//			}
//			cout << "\n-----------------------------------------------------------------\n";
		}
	} while (next_permutation(p+1, p+n+1));
	
	cout << ans;
	return 0;
}

