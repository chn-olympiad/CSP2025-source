#include <bits/stdc++.h>
#define ls cur << 1
#define rs cur << 1 | 1
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
typedef long long ll;
using namespace std;
const int N = 5e5 + 10;
int f[N], a[N], pmx[N];
int main() // ÎÄ¼þ¶ÁÐ´ 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k; cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n)
	{
		int x = pmx[i - 1];
		int cm = 0;
		repf(j, i, 1)
		{
			if(pmx[j - 1] - x > 1) break; 
			cm ^= a[j];
			if(cm == k) {f[i] = pmx[j - 1] + 1; break;}
		}
		pmx[i] = max(pmx[i - 1], f[i]);
	}
	cout << pmx[n];
	return 0;
} 
