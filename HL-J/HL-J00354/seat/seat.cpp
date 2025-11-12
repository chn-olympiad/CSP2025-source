#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int b[20][20];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	bool ck = false;
	int n, m, ans;
	cin >> n >> m;
	int tmp = n * m;
	for (int i = 1; i <= tmp; i++)
		cin >> a[i];
	ans = a[1];
	sort(a + 1, a + tmp + 1, cmp);
	int i = 1, j = 1,k = 1;
	while (1) {
		b[i][j] = a[k++];
		if (b[i][j] == ans) {
			cout << j <<" "<< i << endl;
			break;
		}
		if (i == n && j != m) {
			j++;
			ck = true;
			continue;
		}
		if (i == 1) {
			ck = false;
			if (j != 1) {
				j++;
				continue;
			}
		}
		if (ck == true) {
			i--;
		}
		else {
			i++;
		}
	}
	return 0;
}