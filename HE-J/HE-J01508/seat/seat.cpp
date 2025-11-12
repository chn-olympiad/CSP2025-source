#include <bits/stdc++.h>
using namespace std;
int rw[11][11];
int a[1005];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,r;
	cin>>n>>m;
	x=n*m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=x;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=x;i++)
	{
		for(int q=i+1;q<=x;q++)
		{
			if(a[i]<a[q])
			{
				swap(a[i],a[q]);
			}
		}
	}
	int oi=1;
	bool p=0;
	for(int i=1;i<=m;i++)
	{
		if(!p)
		{
			for(int q=1;q<=n;q++)
			{
				rw[q][i]=a[oi];
				oi++;
			}
		}else
		{
			for(int q=n;q>=1;q--)
			{
				rw[q][i]=a[oi];
				oi++;
			}
		}
		p=!p;
	}
	for(int i=1;i<=m;i++)
	{
		for(int q=1;q<=n;q++)
		{
			if(r==rw[q][i])
			{
				cout<<i<<' '<<q;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }

