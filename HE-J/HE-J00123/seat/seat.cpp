#include <bits/stdc++.h> 
using namespace std;

struct abc {
	long long id;
	long long score;
};
bool cmp(abc x, abc y) {
	return x.score > y.score;
}
abc a[100007];

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long p = n * m;
	for (int i = 1; i <= p; i++) {
		cin >> a[i].score;
		a[i].id = i;
	}
	sort (a + 1, a + p + 1, cmp);
	
	long long s;
	for (int i = 1; i <= p; i++) {
		if (a[i].id == 1) {
			s = i;
			break;
		}
	}
//	cout << s << endl;
	long long x, y;
	if (s % (2 * n) == 0) x = 1;
	else if (s % (2 * n) <= n) x = s % (2 * n);
	else x = s % (2 * n) - n + 1;
	
//	cout << s << endl;
	if (s % n == 0) y = s / n;
	else y = (s / n) + 1;
	
	cout << y << " " << x;
	return 0;
} 
