#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[15][15],n,m,cj[105],R;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1; i<=n*m; i++)
	{
		cin>>cj[i];
	}
	R=cj[1];
	sort(cj+1,cj+(n*m)+1,cmp);
	for(int j=1; j<=m; j++)
	{
		int pos=1;
		if(j%2==1)
		{
			for(int i=1; i<=n; i++)
			{
				a[i][j]=cj[(j-1)*m+pos];
				pos++;
			}
		}
		else
		{
			for(int i=n; i>=1; i--)
			{
				a[i][j]=cj[(j-1)*m+pos];
				pos++;
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(a[i][j]==R)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	
	return 0;
}
