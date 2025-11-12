//GZ-S00040 贵阳市白云区华师一学校 冯子尧 
#include <bits/stdc++.h>

#define upp(a, x, y) for (int a = x; a <= y; a ++)
#define dww(a, x, y) for (int a = x; a >= y; a --)
#define lowbit(x) x & -x
#define pb(x) push_back(x);
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 2e5 + 10;

int n, q;
string s1[N], s2[N];
string st1, st2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	srand(time(NULL));
	
	cin >> n >> q;
	upp (i, 1, n) {
		cin >> s1[i] >> s2[i];
	}
	while (q --) {
		cin >> st1 >> st2;
		cout << 0 << '\n'; 
	}
	return 0;
}
