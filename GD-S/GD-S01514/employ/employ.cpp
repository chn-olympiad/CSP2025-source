#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define PII pair<int,int>
#define rep(k,a,b) for (int k = a;k <= b;k++)
#define all(a) a.begin(),a.end()
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define vct vector
#define endl '\n'
#define sz(a) ((int)a.size())
#define rof(k,a,b) for (int k = a;k >= b;k--)

const int N = 505,M = (1<<18) + 10,mod = 998244353;

int n,m;
string s;
int c[N],p[N];

int f[M][20];

void solvemain()
{
	cin >> n >> m;
	cin >> s;s = ' ' + s;
	rep(i,1,n) cin >> c[i];
	if (n <= 18)
	{
		for (int sb = 0;sb <= n-m;sb++)
			f[0][sb] = 1;
		for (int st = 1;st < (1<<n);st++)
		{
			int pp = __builtin_popcount(st);
			for (int i = 0;i <=(n-pp);i++)
			{
				for (int j = 0;j < n;j++)
					if (st >> j & 1)
					{
						int nst = st ^ (1<<j);
						int sb = i;
						if (s[n-pp+1] == '0' || c[j + 1] <= sb) sb++;
						(f[st][i] += f[nst][sb])%=mod;
					}
			}
		}
		cout << f[(1<<n) - 1][0] << endl;
		return;
	}
	if (n <= 10)
	{
		int ans = 0 ;
		rep(i,1,n) p[i] = i;
		do
		{
			int sb = 0;
			for (int i = 1;i <= n;i++)
			{
				if (s[i] == '0' || c[p[i]] <= sb) sb++;
			}
//			cout << sb << endl;
			if (sb <= n - m) ans++;
		}while (next_permutation(p + 1,p + n + 1));
		cout << ans <<endl;
		return;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t ;t = 1;
	while (t--) {
		solvemain();
	}
	return 0;
}
/*
3 2
101
1 1 2


*/

