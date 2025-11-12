#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int n, m;
char a[505];
int w[505], v[505], p[505];
int ans;
bool AA()
{
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] == '0') return false;
	}
	return true;
}
int jc(int x)
{
	int sum = 1;
	for(int i = 2;i <= x;i ++)
	{
		sum *= i;
	}
	return sum;
}
bool check(int x[])
{
	int num = 0, sum = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(x[i] <= num || a[i] == '0')
		{
			num ++;
			continue;
		}
		sum ++;
	}
	return sum >= m;
}
void dfs(int pos)
{
	if(pos == n + 1)
	{
		if(check(p))
		{
			ans ++;
		}
		return ;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(!v[i])
		{
			p[pos] = w[i];
			v[i] = 1;
			dfs(pos + 1);
			v[i] = 0;
			p[pos] = 0;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++) cin >> w[i];
	if(AA())
	{
		cout << jc(n);
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}

