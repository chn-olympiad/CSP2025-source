#include<bits/stdc++.h>
#define int long long
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define maxn 5005
#define mod 998244353
#define endl "\n"
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;
int a[maxn];
int cs[maxn];
int C[maxn][maxn];//i choose j
int n;


void solve_1_to_10()
{
	sort (a + 1 ,a + n + 1);
	int tot = 0;
	for (int u = 3 ;u <= n ;u ++)
	{
		memset (cs ,0 ,sizeof cs);
		for (int i = 1 ;i <= u ;i ++)	cs[i] = 1;
		do
		{
			int cnt = 0 ,res = 0;
			for (int i = 1 ;i <= n ;i ++)
			{
				if (cnt == u - 1)	break;
				cnt += cs[i];
				res += a[i] * cs[i];
			}
			int mma;
			for (int i = n ;i >= 1 ;i --)
			{
				if (cs[i])
				{
					mma = a[i];
					break;
				}
			}
			if (mma < res)	tot ++;
		}while (prev_permutation (cs + 1 ,cs + n + 1));
	}
	cout << tot << endl;
	return ;
}


void solve_15_to_20()
{
	for (int i = 1 ;i <= 5000 ;i ++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1 ;i <= 5000 ;i ++)
		for (int j = 1 ;j < i ;j ++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	int ans = 0;
	for (int i = 3 ;i <= n ;i ++)	ans = (ans + C[n][i]) % mod;
	cout << ans << endl;
	return ;
}


signed main()
{
	I AK CSP
	freopen ("polygon.in" ,"r" ,stdin);
	freopen ("polygon.out" ,"w" ,stdout);
	cin >> n;
	bool flag = 1;
	for (int i = 1 ;i <= n ;i ++)
	{
		cin >> a[i];
		if (a[i] != 1)	flag = 0;
	}
	if (flag)	solve_15_to_20 ();
	else	solve_1_to_10 ();
	return 0;
}//Code by Lyyq.
//wage