#include<bits\stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,q,s,d=0,t,b,v;
	int a[10000];
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i];
	}
	v=a[0];
	for(int s=0;s<m*n;s++)
	{
		for(int k=0;k<m*n;k++)
		{
			if(a[s]>a[k])
			{
				q=a[k];
				a[k]=a[s];
				a[s]=q;
			}
		}
	}
	for(int u=0;u<m*n;u++)
	{
		if(a[u]!=v)
		{
			d=d+1;
		}
		else
		{
			break;
		}
	}
	d=d+1;
	if(d>m)
	{
		s=d%m;
		t=d/m+1;
		if(t%2!=0)
		{
			cout<<t<<" "<<s;
		}
		else
		{
			b=m-s+1;
			cout<<t<<" "<<b;
		}	
	}
	else
	{
		cout<<"1"<<" "<<d;
	}
	return 0;
	
}
