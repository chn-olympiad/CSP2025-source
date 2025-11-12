#include<bits/stdc++.h> //exp:100pts
using namespace std;
template <typename _Tp>
void read(_Tp &res) {
	res = 0;
	bool f = 0;
	char ch = getchar();
	while (ch < '0' ||  ch > '9')
		f |= (ch == '-'), ch = getchar();
	while (ch >= '0' && ch <= '9')
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	res = f ? -res : res;
}
constexpr int MAXN = 105;
int n, m;
int little_R, stu[MAXN];
int row, line;
int main() {
#if DEBUG
	freopen(".\\seat\\seat3.in", "r", stdin);
	freopen(".\\seat\\seat3.out", "w", stdout);
//	cerr << "start running!\n";
#else
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
#endif
	read(n), read(m);
	for (int i = 1; i <= n * m; ++i)
		read(stu[i]);
	little_R = stu[1];
	sort(stu + 1, stu + n * m + 1);
	int upper_pos = lower_bound(stu + 1, stu + n * m + 1, little_R) - stu;		
	int upper_than_little_R = n * m - upper_pos + 1;
	line = (upper_than_little_R / (n * 2)) * 2;
	upper_than_little_R %= (n *  2);
	line += (upper_than_little_R / n) + 1;
	int Remain = upper_than_little_R % n;
	row = (upper_than_little_R > n ? n - Remain + 1 : Remain + 1);
	cout << line << ' '<< row;
	return 0;
}