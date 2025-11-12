#include<bits/stdc++.h>
using namespace std;
long long a[5010],ans,k;
int n;
void qwq(int u,long long mx)//第u个数最大 
{
	if(k < mx)
	{
		ans++;
		ans %= 998244353;
	}
	for(int i = u - 1;i >= 1;i--)
	{
		qwq(i,mx + a[i]);
	}
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 3;i <= n;i++)
	{
		k = a[i];
		qwq(i,0);
	}
	cout << ans % 998244353;
	return 0;
}
