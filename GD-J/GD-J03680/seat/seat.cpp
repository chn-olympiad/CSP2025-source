#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out cout << "sb\n";

const int N = 1005;

int n, m, pos, a[N];

int main() {
//	system("fc seat.out seat.ans");
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	IOS;
	cin >> n >> m;
	cin >> a[1];
	int st = a[1];
	for (int i = 2; i <= n * m; i++) cin >> a[i];
	sort(a + 1, a + n * m + 1, greater<int> ());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == st) {
			pos = i;
			break;
		}
	}
//	cin >> pos;
	int row = pos % n, col = pos / n;
//	cout << col << ' ' << row << "\n"; 
	if (row) col++;
	if (!(col & 1)) {
		if (row == 0) row = 1;	
		else row = n - row + 1;
	}
	if ((col & 1) && row == 0) row = n;
	cout << col << ' ' << row << "\n"; 
	return 0;
}

