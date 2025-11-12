#include<bits/stdc++.h>
using namespace std;
int a[5005], n, ans;
bool vis[5005];
void dfs(int step, int endflag, int maxn, int cnt, int last/*, string str*/)
{
	if(step > endflag)
	{
//		cout << str << endl; 
		if(cnt > 2 * maxn)ans = (ans + 1) % 998244353;
		return;
	}
	for(int i = last + 1; i <= n; i ++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			dfs(step + 1, endflag, max(maxn, a[i]), cnt + a[i], i/*, str + to_string(a[i])*/);
			vis[i] = 0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	bool A = 1;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		if(a[i] != 1)A = 0;
	}
	if(A)
	{
		int ansa = 0;
		for(int i = 1; i <= n; i ++)
		{
			ansa = (ansa + i) % 998244353;
		}
		cout << ansa << endl;
	}
	else
	{
		for(int i = 3; i <= n; i ++)dfs(1, i, 0, 0, 0/*, ""*/); 
		cout << ans << endl;
	}
	return 0;
}
//998244353 
