#include<bits/stdc++.h>
using namespace std;

int a[10000][10000];


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int num = 1;
	int b = 0;
	int n = 0;
	int m = 0;
	int c = 0;
	int r = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(a[1][1] < a[i][j]) num++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		c++;
		if(i % 2 == 0) r = n+1;
		else r = 0;
		for(int j = 1;j <= n;j++)
		{
			if(i%2 == 0)
			{
				r--;
			}else{
				r++;
			}
			b++;
			if(num == b)
			{
				cout<<c<<" "<<r;
				return 0;
			}
		}
	}
	return 0;
	
}