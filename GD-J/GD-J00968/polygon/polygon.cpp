#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e3 + 5;
const int mod = 998244353;

ll ans2;
int n,k;
int a[N];
bool cmp(int x,int y){return x>y;}
int dfs(int step,ll ans)
{
	if (step>n)
	{
		if (ans>=k)return 1;
		return 0;
	}
	return (dfs(step+1,ans+a[step])+dfs(step+1,ans))%mod;
}
void gc()
{
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n;i++)
	{
		k = a[i]+1;
		ans2=(ans2+dfs(i+1,0))%mod;
	}
	cout << ans2;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	gc();
	return 0;
} 
