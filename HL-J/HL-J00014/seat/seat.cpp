#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int r,c;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int k = a[1];
	int x = n * m;
	//cout << k << endl;
	sort(a+1,a+x+1,cmp);
	//cout << a[2] << endl;
	int l = 0;
	for(int i = 1;i <= x;i++)
	{
		if(a[i] == k)
		{
			l = i;
			//cout << i << endl;
		}
	}
	//int c = l/n+1;
	if(l % n == 0)
	{
		c = l / n;
		r = n;
	}
	else
	{
		c = l / n + 1;
		if(c % 2 == 1)
		{
			r = l % n;
		}
		else
		{
			r = n -(l % n)+1;
		}
	}
	cout << c << " " << r;
	return 0;
}

