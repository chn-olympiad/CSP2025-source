#include <bits/stdc++.h>
using namespace std;
int ans =1;
int a[105],b[105];
int seat[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int zong = n*m;
	for(int i = 1;i<=zong;i++)
	{
		cin >> a[i];
	}
	int R = a[1];
	int pts = 0;
	sort(a+1,a+zong+1);
	for(int i = 1;i<=zong;i++)
	{
		b[i] = a[zong-i+1];
		if(b[i] == R)
		{
			pts=i;
		}
	}
	int c,r;
	if(pts < n)
	{
		c =1;
	}
	else{
		c = (pts-1)/n +1;
	}
	if(pts < n)
	{
		r = pts;
	}
	else
	{
		if(c % 2 == 0)
		{
			int val = pts % n;
			r = n -val+1;
		}
		else
		{
			if(pts%n != 0) r = pts%n+1;
			else r = n;
			
		}
	}
	cout << c << " " << r;
	return 0;
}
