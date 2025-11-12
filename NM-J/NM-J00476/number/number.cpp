#include <bits/stdc++.h>
#define ls cur << 1
#define rs cur << 1 | 1
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
typedef long long ll;
using namespace std;
const int N = 1e6 + 10;
char s[N];
int a[N], tot;
int main() // ÎÄ¼þ¶ÁÐ´ 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s + 1;
	int n = strlen(s + 1);
	rep(i, 1, n) if(s[i] >= '0' && s[i] <= '9') a[++ tot] = s[i] - '0';
	sort(a + 1, a + 1 + tot);
	reverse(a + 1, a + 1 + tot);
	rep(i, 1, tot) cout << a[i];
	return 0;
} 
