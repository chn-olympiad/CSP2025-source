#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct tx
{
	int id,a1,a2,a3;
} re1[maxn],re2[maxn],re3[maxn];

int n,a[maxn][5];
int mx1 = -1e9,vis1[15];
void dfs1(int dep)
{
	if(dep == n+1)
	{
		int cnt1[5] = {0,0,0,0,0};
		int ans1 = 0;
		for(int i = 1;i <= n;i++)
		{
			cnt1[vis1[i]]++;
			ans1 += a[i][vis1[i]];
		}
		if(cnt1[1] > n/2 || cnt1[2] > n/2 || cnt1[3] > n/2)  return;
		mx1 = max(mx1,ans1);
		return;
	}
	vis1[dep] = 1;
	dfs1(dep+1);
	vis1[dep] = 2;
	dfs1(dep+1);
	vis1[dep] = 3;
	dfs1(dep+1);
}

int dp1[35][25][25][25];
int dfs2(int dep,int _1,int _2,int _3)
{
	if(dp1[dep][_1][_2][_3]) return dp1[dep][_1][_2][_3];
	if(dep == n+1) return 0;
	if(_1 > n/2) return 0;
	if(_2 > n/2) return 0;
	if(_3 > n/2) return 0;
	int ans = 0;
	if(_1+1 <= n/2)
	{
		int now = dfs2(dep+1,_1+1,_2,_3);
		ans = max(ans,now+a[dep][1]);
	}
	if(_2+1 <= n/2)
	{
		int now = dfs2(dep+1,_1,_2+1,_3);
		ans = max(ans,now+a[dep][2]);
	}
	if(_3+1 <= n/2)
	{
		int now = dfs2(dep+1,_1,_2,_3+1);
		ans = max(ans,now+a[dep][3]);
	}
	dp1[dep][_1][_2][_3] = ans;
	return ans;
}
int dp2[110][110][110];
int dfs3(int _1,int _2,int _3)
{
	int dep = _1+_2+_3;
	if(dp2[_1][_2][_3]) return dp2[_1][_2][_3];
	if(dep == n+1) return 0;
	if(_1 > n/2) return 0;
	if(_2 > n/2) return 0;
	if(_3 > n/2) return 0;
	int ans = 0;
	if(_1+1 <= n/2)
	{
		int now = dfs3(_1+1,_2,_3);
		ans = max(ans,now+a[dep][1]);
	}
	if(_2+1 <= n/2)
	{
		int now = dfs3(_1,_2+1,_3);
		ans = max(ans,now+a[dep][2]);
	}
	if(_3+1 <= n/2)
	{
		int now = dfs3(_1,_2,_3+1);
		ans = max(ans,now+a[dep][3]);
	}
	dp2[_1][_2][_3] = ans;
	return ans;
}
bool cmpA(tx x,tx y)
{
	if(x.a1 != y.a1) return x.a1 > y.a1;
	return x.a2 < y.a2;
}
bool cmpB(tx x,tx y)
{
	if(x.a2 != y.a2) return x.a2 > y.a2;
	return x.a1 < y.a1;
}
bool cmpC(tx x,tx y)
{
	if(x.a3 != y.a3) return x.a3 > y.a3;
	return x.id < y.id;
}
int dp[maxn][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--)
	{
		cin >> n;
		bool flagA = 1,flagB = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
				cin >> a[i][j];
			re1[i].a1 = re2[i].a1 = re3[i].a1 = a[i][1];
			re1[i].a2 = re2[i].a2 = re3[i].a2 = a[i][2];
			re1[i].a3 = re2[i].a3 = re3[i].a3 = a[i][3];
			if(a[i][2] != 0) flagA = 0;
			if(a[i][3] != 0) flagB = 0;
		}
		if(n <= 10)
		{
			memset(vis1,0,sizeof(vis1));
			mx1 = -1e9;
			dfs1(1);
			cout << mx1 << endl;
			continue;
		}
		if(n <= 30)
		{
			memset(dp1,0,sizeof(dp1));
			cout << dfs2(1,0,0,0) << endl;
			continue;
		}
		if(n <= 200)
		{
			memset(dp2,0,sizeof(dp2));
			cout << dfs3(0,0,0) << endl;
			continue;
		}
		if(flagA)
		{
			int sumA = 0;
			sort(re1+1,re1+n+1,cmpA);
			for(int i = 1;i <= n/2;i++)
				sumA += re1[i].a1;
			cout << sumA << endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][2];
		dp[1][3] = a[1][3];
		for(int i = 2;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				dp[i][j] = max(dp[i-1][1]+a[i][j],dp[i][j]);
				dp[i][j] = max(dp[i-1][2]+a[i][j],dp[i][j]);
				dp[i][j] = max(dp[i-1][3]+a[i][j],dp[i][j]);
			}
		}
		cout << max(max(dp[n][1],dp[n][2]),dp[n][3]) << "\n";
	}
	return 0;
}

