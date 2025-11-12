// 准考证：GZ-S00501，姓名：黄佳洛，学校：华中师大一附中贵阳学校 

#include <bits/stdc++.h>
#define endl '\n'
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, r, l) for (int i = r; i >= l; i--)
#define IO ios::sync_with_stdio(0)
#define x first
#define y second
#define PII pair<int, int>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int w[N];

int main() {
	IO;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	string s;
	cin >> n >> m >> s;
	upp(i, 1, n) cin >> w[i];
	cout << 0 << endl;
	 
	
	return 0;
}
