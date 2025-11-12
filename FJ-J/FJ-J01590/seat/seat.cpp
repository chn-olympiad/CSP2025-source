#include <iostream>
#include <algorithm>
using namespace std;

int n, m, p;

struct node {
	int val, id;
}s[105];

bool cmp(node x, node y) {
	return x.val > y.val;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> s[i].val;
		s[i].id = i;
	}
	p = s[1].val;
	sort(s + 1, s + n * m + 1, cmp);
	int idd;
	for(int i = 1; i <= n * m; i++) {
		if(s[i].id == 1) idd = i;
	}
	int q1 = (idd - 1) / n + 1, q2;
	if(q1 & 1) q2 = idd - (q1 - 1) * n;
	else q2 - n - (idd - (q1 - 1) * n) + 1;
	cout << q1 << " " << q2;
}
