#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],man,l,h;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i*m+j];
		}
	}
	man=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(man==a[i*m+j])
			{
				man=i*m+j;
			}
		}
	}
	if(man%m==0)
	{
		l=man/n;
	}
	else
	{
		l=man/n+1;
	}
	
	if(l%2==0)
	{
		h=n-((man-1)%n);
	}
	else
	{
		h=man%n;
		if(h==0)
		{
			h=n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
} 
