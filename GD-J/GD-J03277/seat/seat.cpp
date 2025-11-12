#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,xx,yy;
int a[20];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	k = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == k)
		{
			u = i;
		}
	}
	xx = u % n;
	if(xx == 0)
	{
		xx = n;
	}
	yy = u / n;
	if(u % n != 0)
	{
		yy++;
	}
	if(yy % 2 == 0)
	{
		xx = n - xx + 1;
	}
	cout << yy << " " << xx;
	return 0;
}
