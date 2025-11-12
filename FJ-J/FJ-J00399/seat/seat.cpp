#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int r,n,m,s=0,a;
	cin>>n>>m>>r;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>a;
		if(a>r)
		{
			s++;
		}
	}
	s++;
	int l,p;
	if(s%n==0)
	{
		l=s/n;
	}
	else
	{
		l=s/n+1;
	}
	if(l%2==1)
	{
		p=s%n;
		if(p==0)
		{
			p=n;
		}
	}
	else
	{
		p=n-s%n+1;
		if(s%n==0)
		{
			p=1;
		}
		
	}
	cout<<l<<" "<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}