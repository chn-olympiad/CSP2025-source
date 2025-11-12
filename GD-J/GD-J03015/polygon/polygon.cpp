#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
long long ans = 0;
int a[5005],n;
void dfs(int cur,int sum,int maxx,int num,bool f)
{
	if (cur > n) return;
	if (sum > a[maxx] * 2 && num >= 3 && !f) 
	{
		ans++;
		//cout << "//" << cur << " " << sum << " " << maxx << " " << num << endl;
	}
	dfs(cur + 1,sum,maxx,num,true);
	dfs(cur + 1,sum + a[cur + 1],cur + 1,num + 1,false);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool pf = true;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] > 1) pf = false;
	}
	if (pf)
	{
		for (int i = 3;i <= n;i++)
		{
			long long sum = 1;
			for (int j = 0;j < i;j++)
				sum = (sum * (n - j) / (j + 1)) % mod;
			ans = (ans + sum) % mod;
		}
		cout << ans;
		return 0;
	}
	sort(a + 1,a + n + 1);
	dfs(0,0,0,0,false);
	cout << ans % mod;
	return 0;
}
