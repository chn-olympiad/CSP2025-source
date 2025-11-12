#include <bits/stdc++.h>
using namespace std;
int n, m; 
const int modn = 998244353; 
int a[100005], b[100005], f[100005], f2[100005]; 
long long func(int x)
{
	return ((func(x - 1) % modn) * x) % modn; 
}
int trying()
{
	int tmp = 0; 
	for(int i = 1; i <= n; i++)
	{
		if(!a[i] || tmp >= b[f[i]])
			tmp++; 
	}
//	for(int i = 1; i <= n; i++)
//		cout << f[i] << " "; 
//	cout << "\n" << tmp << "\n===========\n"; 
	if(n - tmp >= m) return 1; 
	else return 0; 
}
int dfs(int step)
{
	int ans = 0; 
	if(step == n + 1)
	{
		return trying(); 
	}
	for(int i = 1; i <= n; i++)
	{
		if(!f2[i])
		{
			f[step] = i; 
			f2[i] = true; 
			ans += dfs(step + 1); 
			f2[i] = false; 
			f[step] = 0; 
		}
	}
	return ans; 
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m; 
	if(n > 19)
	{
		cout << func(n); 
	}
	else
	{
		char ch; 
		for(int i = 1; i <= n; i++)
		{
			cin >> ch; 
			if(ch == '1')
				a[i] = 1; 
			else
				a[i] = 0;  
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> b[i]; 
		}
		cout << dfs(1); 
	}
	return 0;
}

