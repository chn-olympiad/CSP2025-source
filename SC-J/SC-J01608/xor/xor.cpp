#include<bits/stdc++.h>
#define int long long
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define maxn 500005
#define endl "\n"
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;
int pre[maxn] ,dp[maxn] ,a[maxn];
int n ,k;
struct node
{
	int l ,r;
}lin[1000005];
int top;


void solve_1_to_12(int n ,int k)
{
	for (int i = 1 ;i <= n ;i ++)	cin >> a[i];
	for (int i = 1 ;i <= n ;i ++)	pre[i] = pre[i - 1] ^ a[i];
	for (int i = 1 ;i <= n ;i ++)
		for (int j = 1 ;j <= i ;j ++)
			if ((pre[i] ^ pre[j - 1]) == k)
				lin[++ top].l = j ,lin[top].r = i;
	int ans = 0;
	for (int j = 1 ;j <= top ;j ++)
		for (int i = n ;i >= 1 ;i --)
		{
			if (lin[j].r <= i)
				dp[i] = max (dp[i] ,dp[lin[j].l - 1] + 1);
		}
		
	cout << dp[n] << endl;
	return ;
}


void solve_13_k_1(int n ,int k)
{
	for (int i = 1 ;i <= n ;i ++)	cin >> a[i];
	int ans = 0;
	for (int i = 1 ;i <= n ;i ++)	ans += a[i];
	cout << ans << endl;
	return ;
}


void solve_13_k_0(int n ,int k)
{
	for (int i = 1 ;i <= n ;i ++)	cin >> a[i];
	int ans = 0;
	for (int i = 1 ;i <= n ;i ++)
	{
		if (a[i] == 0)	ans ++;
		if (a[i] == 1)
		{
			if (i == n)
				break;
			else if (a[i + 1] == 0)
				continue;
			else
				ans ++ ,i ++;
		}
	}
	cout << ans << endl;
}


signed main()
{
	I AK CSP
	freopen ("xor.in" ,"r" ,stdin);
	freopen ("xor.out" ,"w" ,stdout);
	cin >> n >> k;
	if (k == 1)	solve_13_k_1 (n ,k);
	else if (k == 0)	solve_13_k_0 (n ,k);
	else	solve_1_to_12 (n ,k);
	return 0;
}//Code by Lyyq.
//wage