#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;

struct node {
	int val, id;
}a[N];

bool cmp(node x, node y) {
	return x.val > y.val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i].val;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int flag = 1, x = 1, y = 1;
	for(int i = 1; i <= n * m; i++) {
		if(i != 1) {
			if((y == n && flag == 1) || (y == 1 && flag == -1)) {
				x++;
				flag = -flag;
			}
			else y += flag;
		}
		if(a[i].id == 1) {
			cout << x << ' ' << y << endl;
			break;
		}
	}
	return 0;
}
