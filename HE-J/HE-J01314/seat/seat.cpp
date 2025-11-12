#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,y,u,v,l,a1,a2,a3;
	int a[15][15]={0};
	l=0;
	a2=0;
	cin>>n>>m;
	y=n*m;
	a3=n-1;
	int f[110]={0};
	for(int i=0;i<y;i++)
	{
		cin>>f[i];
	}
	v=f[0];
	for(int t=0;t<y;t++)
	{
		for(int x=0;x<y;x++)
	{
		if(f[x]<=f[x+1])
		{
			u=f[x];
			f[x]=f[x+1];
			f[x+1]=u; 
		}
	}
	}

	for(int e=0;a2<m;e++);
	{
		a1=0;
			for(int w=0;w<n;w++);
		{
			a[a1][a2]=f[l];
			a1++;
		l++;
		}
		a2++;
		if(a2==m)
		{
		for(int z1=0;z1<n;z1++)
		{
			for(int h1=0;h1<m;h1++)
			{
				if(a[z1][h1]==v)
				{
					cout<<h1+1<<" "<<z1+1;
					return 0;
				}
			}
		}
	}
	a2++;
	for(int q=n-1;q=0;q--);
	{
	a[a3][a2]=f[l];
	a3--;
	l++;
	}
	a2++;
}
	for(int z=0;z<n;z++)
	{
		for(int h=0;h<m;h++)
		{
			if(a[z][h]==v)
			{
				cout<<h+1<<" "<<z+1;
			}
		}
	}
	return 0;
}
