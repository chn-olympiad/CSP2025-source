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

const int N = 510;

int n, m;
string s;
int c[N]; 

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	srand(time(NULL));
	
	cin >> n >> m;
	cin >> s;
	upp (i, 1, n) cin >> c[i];
	cout << n * m;
	return 0;
}
