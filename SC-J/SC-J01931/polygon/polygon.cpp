#include <bits/stdc++.h>
using namespace std;
const int MAXN = 998244353;
int n;
void dfs(int t,int maxn,int l,int &cnt,vector<int> &h)
{
	if (t > n)
	{
		if (l > maxn*2)
		{
			cnt = (cnt+1) % MAXN;
		}
		return ;
	}
	dfs(t+1,max(maxn,h[t]),l+h[t],cnt,h);
	dfs(t+1,maxn,l,cnt,h);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt = 0;
	bool flag = true;
	cin >> n;
	vector<int> h(n+1);
	for (int i = 1;i <= n;i++)
	{
		cin >> h[i];
		if (h[i] != 1)
		{
			flag = false;
		}
	}
	if (flag)
	{
		for (int i = 3;i <= n;i++)
		{
			int num = n,cntt = 1;
			for (int j = i;j >= 1;j--)
			{
				cntt *= num;
				num--;
			}
			for (int j = i;j >= 1;j--)
			{
				cntt /= j;
			}
			cnt = (cnt+cntt) % MAXN;
		}
	}
	else dfs(1,0,0,cnt,h);
	cout << cnt;
	return 0;
} 