#include<iostream>
#include<algorithm>
using namespace std;

int p[15][15];
int n,m;
int a[121];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	
	
	int x = a[1];
	
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n;i++)
	{
		if(i%2 == 1)
		{
			for(int j=1;j<=m;j++)
			{
				p[i][j] = a[(i-1)*n + j];
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				p[i][j] = a[(i-1)*n + m-j+1];
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(p[i][j] == x)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
