#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct P
{
	int aa,bb,cc;
} a[100005];
bool cmp(P x,P y)
{
	return x.aa - x.bb > y.aa - y.bb;
}
int n,f[35];
long long ans;
void dfs(int x)
{
	if (x == n + 1)
	{
		int cnt[5] = {0,0,0,0,0};
		for (int i = 1;i <= n;i++)
		{
			cnt[f[i]]++;
			if (cnt[f[i]] > n / 2)
				return;
		}
		long long summ = 0;
		for (int i = 1;i <= n;i++)
		{
			if (f[i] == 1)
				summ += a[i].aa;
			else if (f[i] == 2)
				summ += a[i].bb;
			else
				summ += a[i].cc;
		}
		//cout << summ << endl;
		ans = max(ans,summ);
		return;
	}
	f[x] = 1;
	dfs(x + 1);
	f[x] = 2;
	dfs(x + 1);
	f[x] = 3;
	dfs(x + 1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;
		memset(f,0,sizeof(f));
		for (int i = 1;i <= n;i++)
		{		
			cin >> a[i].aa >> a[i].bb >> a[i].cc;
		}
		if (n <= 10)
		{
			dfs(1);
			cout << ans << endl;
		}
		else
		{
			long long sum = 0;
			sort(a + 1,a + n + 1,cmp);
			for (int i = 1;i <= n / 2;i++)
				sum += a[i].aa;
			for (int i = n / 2 + 1;i <= n;i++)
				sum += a[i].bb;
			cout << sum << endl;
		}
	}
}
