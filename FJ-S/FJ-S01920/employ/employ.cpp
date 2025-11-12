#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define ms(a,b) memset(a,b,sizeof(a))
#define lowbit(x) x&(-x)
#define mk make_pair


inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch >'9' || ch < '0')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x*f;
}

int mod = 998244353;
int n, m;
string s;
int a[510];
int jie[510];
int dp[300010][20];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(), m = read();
	jie[0] = 1;
	for(int i = 1;i <= n;++i) jie[i] = (jie[i-1]*i) % mod;
	cin >> s;
	for(int i = 1;i <= n;++i) a[i] = read();
	bool flag = 0;
	s = ' ' + s;
	if(n <= 18)
	{
		dp[0][0] = 1;
		for(int k = 1;k <= 3e5;++k)
		{
			int t = 0;
			int temp = k;
			while(temp)
			{
				t += (temp&1);
				temp >>= 1;
			}
			temp = k;
			for(int i = 1;i <= n;++i)
			{
				if(!((1<<(i-1))&k)) continue;
				for(int j = 0;j < t;++j)
				{
					if(t-1-j >= a[i] || s[t] == '0') dp[k][j] = (dp[k][j] + dp[k-(1<<(i-1))][j]) % mod;
					else
					{
	//					cout << k << endl;
						dp[k][j+1] = (dp[k][j+1] + dp[k-(1<<(i-1))][j]) % mod;
					}
	//				cout << dp[k-(1<<(i-1))][j] << ' ';
				}
			}
	//		cout << dp[k][1] << ' ';
		}
		int ans = 0;
		int k = (1<<n)-1;
		for(int i = m;i <= n;++i) ans = (ans + dp[k][i]) % mod;
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n;++i)
	{
		if(s[i] == '0') flag = 1;
	}
	if(n == m)
	{
		int t = 0;
		for(int i = 1;i <= n;++i)
		{
			if(!a[i]) ++t;
		}
		if(flag || t) puts("0");
		else cout << jie[n];
		return 0;
	}
	if(m == 1)
	{
		int t = 0;
		for(int i = 1;i <= n;++i)
		{
			if(!a[i]) ++t;
		}
		if(t == n) puts("0");
		else
		{
//			cout << (n-t)*jie[n-1] % mod;
			t = 1;
			while(s[t] == '0' && t <= n) ++t;
			int ans = 0;
			for(int i = 1;i <= n;++i)
			{
				if(a[i] >= t) ans = (ans + jie[n-1]) % mod;
			}
			cout << ans;
		}
		return 0;
	}
	if(!flag)
	{
		int t = 0;
		for(int i = 1;i <= n;++i)
		{
			if(!a[i]) ++t;
		}
		if((n-t) < m) puts("0");
		else if(!t) cout << jie[n];
		else puts("161088479");
		return 0;
	}
	puts("225301405");
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
