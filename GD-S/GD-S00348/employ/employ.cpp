//canpass: 1,2,3,4,5,15
#include <bits/stdc++.h>
#define int long long
#define rep1(i,a,b) for (int i = (a);i <= (b);i++)
using namespace std;
const int N = 510;
const int M = 19;
const int K = (1 << 18) + 10;
const int mod = 998244353;
int n,m;
string st;
int c[N];
int f[K][M],g[N][N];
void add(int& x,int y)
{
	x += y;
	if (x > mod)
		x -= mod;
}
bool specialA()
{
	rep1(i,1,n)
		if (st[i] == '0')
			return false;
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//f[s][j]：s这个集合来面试，一共恰好j个人被录用了，（则拒绝|s|-j人），方案数 
	cin >> n >> m >> st;
	st = ' ' + st;
	rep1(i,0,n - 1)
		cin >> c[i];
	//1~5
	if (n <= 18)
	{
		f[0][0] = 1;
		rep1(s,1,(1 << n) - 1)
		{
			int sz = __builtin_popcount(s);
			int ok = st[__builtin_popcount(s)] - '0';
			//_:在新加这个人之前录用了多少个人 
			rep1(_,0,n - 1)
			{
				//哪个人是新加的 
				rep1(i,0,n - 1)
					if (s & (1 << i))
					{
						//能否录用第i个人 
						if (ok && c[i] > (sz - 1 - _))
							add(f[s][_ + 1],f[s - (1 << i)][_]);
						else
							add(f[s][_],f[s - (1 << i)][_]);
					}
			}
		}
		int ans = 0;
		rep1(j,m,n)
			add(ans,f[(1 << n) - 1][j]);
		cout << ans;
		return 0;
	}
	//15
	if (m == n)
	{
		//所有人必须录用
		rep1(i,1,n)
			if (st[i] == '0')
			{
				cout << 0;
				return 0;
			}
		//s全为1
		//只要将耐心为0的放在前面
		int cnt0 = 0;
		rep1(i,0,n - 1)
			if (c[i] == 0)
				cnt0++;
		if (cnt0 >= 2)
		{
			cout << 0;
			return 0;
		}
		//若cnt0=0:完全随便排
		//若cnt0=1:0放最前面，其余随便排 
		int ans = 1;
		if (cnt0 == 0)
		{
			rep1(i,1,n)
				ans = ans * i % mod;
		}
		else
		{
			rep1(i,1,n - 1)
				ans = ans * i % mod;
		}
		cout << ans;
		return 0; 
	}
}

