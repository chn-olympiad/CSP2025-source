#include <iostream>
#include <algorithm>
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define ll long long 
#define rop(i, j, k) for(int i = j; i >= k; i--)
#define big __int128
#define ull unsigned ll 
using namespace std;
const int N = 1e5 + 5, mod = 998244353;
ll res;
int n, m, a[N], p[N], c[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n){
		char ch;
		cin >> ch;
		a[i] = ch - '0';
		p[i] = i;
	}
	rep(i, 1, n) cin >> c[i];
	do{
		int now = 0;
		rep(i, 1, n){
			if(now >= c[p[i]]){now++; continue;}
			now += !a[i];
		}
		if(n - now >= m) res++;
	}while(next_permutation(p + 1, p + n + 1));
	res %= mod;
	cout << res;
	return 0;	
} 
