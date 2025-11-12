#include<bits/stdc++.h>
#define ll long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs, mid + 1, r
using namespace std;
const int N = 1e5 + 10;
int n, m, num, ans1 = 1, ans2;
int a[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) {
		cin >> a[i];
	}
	int t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1;i <= n * m;i++) {
		if(a[i] == t) {
			num = i;
			break;
		}
	}
	while(num > n) {
		num -= n;
		ans1++;
	}
	if(ans1 % 2 == 1) {
		ans2 = num;
	} else {
		ans2 = n - num + 1;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}