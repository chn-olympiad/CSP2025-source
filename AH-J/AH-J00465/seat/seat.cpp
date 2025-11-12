#include<bits/stdc++.h>
using namespace std;

const int N = 20,M = 20,S = 110;
int seat[N][M];
int a[S];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,c = 0,r = 0,pos = 0;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	
	int xr = a[1];
	sort(a+1,a+m*n+1,cmp);
	
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == xr)
		pos = i;
	}
	
	if(pos == 1)
	{
		c = 1;
		r = 1;
	}
	
	for(int i = 1;i <= m;i++)
	{
		if(i%2 == 0 && pos == i*n)
		{
			c = i;
			r = 1;
		}
		else if(i%2 == 1 && pos == i*n)
		{
			c = i;
			r = n;
		}
		else if(i%2 == 0 && pos == i*n+1)
		{
			c = i+1;
			r = 1;
		}
		else if(i%2 == 1 && pos == i*n+1)
		{
			c = i+1;
			r = n;
		}
		else if(i%2 == 0 && pos < i*n && pos > (i-1)*n+1)
		{
			c = i;
			r = i*n-pos+1;
		}
		else if(i%2 == 1 && pos > (i-1)*n+1 && pos < i*n)
		{
			c = i;
			r = pos-(i-1)*n;
		}
	}
	
	cout << c << " " << r;
	
	return 0;
}
