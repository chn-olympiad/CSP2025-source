#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[1005], A;
int num[20];
bool Cmp(int _A, int _B) {
	return _A > _B;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	A = a[1];
	sort(a + 1, a + n * m + 1, Cmp);
	int Xx = 1, Yy = 1;
	bool Zhi = 1;
	bool up = 0;
	if(a[1] == A) {
		cout << "1 1";
		return 0;
	}
	for (int i = 2; i <= n * m; i++) {
		if ((Xx == 1 || Xx == n) && !Zhi) ++Yy, up ^= 1, Zhi = 1;
		else Xx = up ? Xx - 1 : Xx + 1, Zhi = 0;
		if (a[i] == A) {
			cout << Yy << ' ' << Xx;
			return 0;
		}
	}
	return 0;
}
//OK 100pts
//注意行和列
