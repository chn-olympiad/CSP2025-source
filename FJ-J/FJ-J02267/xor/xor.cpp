# include <bits/stdc++.h>
using namespace std;

int a[500005], t[500005], ans = -1e9;
int n, k;
int xro(int x, int y)
{
	string ts1, ts2, as;
	while(x != 0)
	{
		ts1 += x % 2 + '0';
		x /= 2;
	}
	while(y != 0)
	{
		ts1 += y % 2 + '0';
		y /= 2;
	}
	for(int i = 0; i < min(ts1.size(), ts2.size()); i++)
	{
		if(ts1[i] - '0' != ts2[i] - '0')
		{
			as += '1';
		}
		else
		{
			as += '0';
		}
	}
	int ans = 0;
	for(int i = as.size(); i >= 0; i--)
	{
		ans += int(pow((as[i] - '0'), as.size() - i));
	}
	return ans;
}

void dfs(int step, int tot)
{
	if(step > n)
	{
		ans = max(ans, tot);
		tot = 0;
		return ;
	}
	if(a[step] == k)
	{
		dfs(step + 1, tot + 1);
	}
	else
	{
		a[step + 1] = xro(a[step], a[step] + 1);
		dfs(step + 1, tot);
	}
}

int main(){
	//freopen("xor.in", "r", stdin);
	//freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
