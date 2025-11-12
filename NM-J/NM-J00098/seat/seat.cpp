#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int a[MAXN];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int k = m * n;
    for (int i = 0; i < k; i++) {
    	cin >> a[i];
	}
	cnt = a[0];
	int idx = 1;
	sort(a, a + k, cmp);
	for (int i = 0; i < k; i++) {
		if (a[i] == cnt) {
			idx += i;
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				idx--;
				if (idx == 0) {
					cout << j << " " << i;
					break;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				idx--;
				if (idx == 0) {
					cout << j << " " << i;
					break;
				}
			}
		}
	}

    return  0;
}


