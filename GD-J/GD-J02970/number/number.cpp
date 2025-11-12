#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 1e6 + 5;

int n;
string s;

int a[N], idx;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	for (auto ch : s)
		if (isdigit(ch))
			a[++ idx ] = ch - '0';
	
	sort(a + 1, a + idx + 1, [](int x, int y){
		return x > y;
	});
	
	for (int i = 1; i <= idx; i ++ ) cout << a[i];
	cout << '\n';

	return 0;
}
