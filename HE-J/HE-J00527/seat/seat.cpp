#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[110];
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pm;
	for(int j=1;j<=n*m;j++)
	{
		if (a[j]==p)
			pm=j;
	}
	int nx,ny;
	if (n>=pm)
	{
		cout<<1<<" "<<pm;
		return 0; 
	}
	if (pm%n!=0)
	{
		ny=pm/n+1;
		if (ny%2==0)
		{
			int u=pm-n*(ny-1);
			nx=n-u+1;
		}
		else
		{
			int u1=pm-n*(ny-1);
			nx=u1;
		}
	}
	else
	{
		ny=pm/n;
		if (ny%2==0)
		{
			int u=pm-n*(ny-1);
			nx=n-u+1;
		}
		else
		{
			int u1=pm-n*(ny-1);
			nx=u1;
		}
	}
	cout<<ny<<" "<<nx;
	return 0; 
} 
