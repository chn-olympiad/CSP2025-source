#include<bits/stdc++.h>
using namespace std;
int n,m;
int l[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> l[i];
	}
	int x = l[1],num = 0,cnt = 0;
	sort(l+1,l+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		cnt++;
		if(l[i] == x)
		{
			num = cnt;
			break;
		}
	}
	int xx = 0;
	if(num%n==0) 
	{
		xx = num/n;
		if(xx % 2 == 0)
		{
			cout << xx << ' ' << 1;			
		}
		else
		{
			cout << xx << ' ' << n;
		}
	}
	else
	{
		xx = num/n + 1;
		int cntt = num - num/n * n;
		if(xx % 2 == 0)
		{
			cout << xx << ' ' << n - cntt + 1;			
		}
		else
		{
			cout << xx << ' ' << cntt;
		}
	}
	return 0;
}
