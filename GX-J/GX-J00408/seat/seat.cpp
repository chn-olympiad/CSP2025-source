#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n,c,s,q,p,sh;
	int a[111]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];	
	}
	s=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[i]>a[j])
			{
				c=a[j];
				a[j]=a[i];
				a[i]=c;
			}
		}
		
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			sh=i-1;
			break;
		}
	}
	
	p=sh/n+1;
	if(p%2!=0)
	{
		q=sh%n+1;
	}
	else
	{
		q=n-sh%n;
	}
	cout<<p<<" "<<q;
	return 0;
}

