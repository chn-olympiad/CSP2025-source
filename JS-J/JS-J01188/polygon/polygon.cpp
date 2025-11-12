#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
void _for(int deep,int s,int need,int add)
{
	if(deep == need)
	{
		for(int i = s + 1;i <= n;i++)
		{
			if(add > a[i]) ans++;
			ans %= 998244353;
		}
		return ;
	}
	for(int i = s + 1;i <= n;i++)
	{
		_for(deep + 1,i,need,add + a[i]);
	}
	ans %= 998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int len = 3;len <= n;len++)
	{
		for(int start = 1;start <= n - len + 1;start++)
		{
			_for(1,start,len - 1,a[start]);
		}
	}
	cout << ans;
	return 0;
}
