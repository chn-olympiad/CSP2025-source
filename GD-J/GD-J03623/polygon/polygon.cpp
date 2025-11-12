#include<bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
int a[5001];
int b[5001];
bool vis[5001];
void xuan(int o,int p)
{
	if(p == o)
	{
		int u = 0;
		int Max = 0;
		for(int i = 1;i <= p;i++)
		{
			Max = max(Max,b[i]);
			u+=b[i];
		}
		if(u > Max*2)
		{
			ans++;
			ans%=998244353;
			return;
		}
	}
	
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 0 && a[i] > b[p-1])
		{
			b[p] = a[i];
			vis[i] = 1;
			xuan(o,p+1);
			vis[i] = 0;
		}
	}
	return;
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 3;i <= n;i++)
	{
		xuan(i,0);
	}
	cout << ans;
	return 0;
}
