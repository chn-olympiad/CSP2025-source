#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, m, x;
struct node {
	int num;
	int id;
}a[N];

bool cmp(node x, node y) {
	return x.num > y.num;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
    	cin >> a[i].num;
    	a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
    	if (a[i].id == 1) {
    		x = i;
    		break;
		}
	}
	if (x % n == 0) cout << x / n << ' ';
	else cout << x / n + 1 << ' ';
	if (x % n != 0 && (x / n + 1) & 1) cout << x % n;
	else if (x % n == 0) {
		if ((x / n) & 1) cout << x % n + n;
		else cout << x % n + 1;
	}	
	else cout << n - (x % n) + 1;
    return 0;
}
