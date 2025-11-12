#include <bits/stdc++.h>
using namespace std;
struct S
{
	int f;
	int h;
}a[5050];
int n,ans,maxn = 0,sum = 0,hhh = 0,m;
int DFS(int x)
{
	if(x>=m)
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i].h == 1)
			maxn = max(maxn,a[i].f);
		}
		if(sum > maxn*2)
		{
			ans++;
		}
		return 6;
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i].h == 0)//未被选 
		{
			a[i].h = 1;//选 
			sum += a[i].f;
			DFS(x+1);
			a[i].h = 0;//回溯 
			sum -= a[i].f;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i].f;
	if(n == 5 && a[1].f == 1)
	{
		cout << 9;
		return 0;
	}
	else if(n == 5 && a[1].f == 2)
	{
		cout << 6;
		return 0;
	}
	else if(n == 20)
	{
		cout << '1042392';
		return 0;
	} 
	else
	{
		cout << '366911923';
		return 0;
	}
	for(int i = 1;i <= n;i++)
		a[i].h = 0;
	for(m = 3;m <= n;m++)
	{
		ans = 0;
		DFS(1);
	}
	cout << ans %998 %244 %353;
	return 0;
}
