#include <bits/stdc++.h>
#define int long long
using namespace std; 

int t,n,a[100005][5],cnta,cntb,cntc,ans;
vector<int> ch;

void dfs(int p)
{
	if(p == n + 1)
	{
		int res = 0;
		for(int i = 1;i <= n;i++)
			res += a[i][ch[i]];
		ans = max(ans,res);
		return;
	}
	for(int i = 1;i <= 3;i++)
	{
		if(i == 1)
		{
			if(cnta + 1 <= n / 2)
			{
				cnta++,ch[p] = i;
				dfs(p + 1);
				ch[p] = 0,cnta--;
			}
		}
		if(i == 2)
		{
			if(cntb + 1 <= n / 2)
			{
				cntb++,ch[p] = i;
				dfs(p + 1);
				ch[p] = 0,cntb--;
			}
		}
		if(i == 3)
		{
			if(cntc + 1 <= n / 2)
			{
				cntc++,ch[p] = i;
				dfs(p + 1);
				ch[p] = 0,cntc--;
			}
		}
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int x = 1;x <= t;x++)
	{
		cin >> n;
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= 3;j++)
				cin >> a[i][j];
		ans = cnta = cntb = cntc = 0;
		ch.clear();
		ch.resize(n + 1);
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
