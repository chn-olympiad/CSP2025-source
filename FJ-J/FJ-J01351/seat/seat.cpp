#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,lrj,a1,a2;
int a[105];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a[1];
	lrj = a[1];
	for(int i = 2;i <= n*m;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == lrj)
		{
			cnt = i;
			break;
		}
	}
	if((cnt%n) == 0)
	{
		a1 = cnt / n;
	}
	else
	{
		a1 = cnt / n + 1;
	}
	if(a1%2==0)
	{
		a2 = n - cnt % n+1;
	}
	else
	{
		a2 = cnt % n;
		if(a2 == 0)
		{
			a2 = n;
		}
	}
	cout << a1  << " " << a2;
	return 0;
}
