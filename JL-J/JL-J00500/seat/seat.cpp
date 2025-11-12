#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[110],x,Max=0,h,b=0,p=0,R,B,r,c;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>s[i];
		
	}
	R=s[1];
	for(int j=1;j<=1000;j++)
	{
		for(int i=1;i<=x;i++)
		{
			if(s[i]>Max&&i!=1)
			{
				h=s[i];
				s[i]=s[i-1];
				s[i-1]=h;
			}
			else if(i==1)
				Max=s[i];
		}
		b=Max;
		for(int i=1;i<=x;i++)
		{
			p=0;
			if(s[i]<b)
			{
				continue;
			}
			else if(s[i]>=b)
			{
				break;
			}
			else if(i==x)
			{
				p=1;
			}
		}
		if(p==1)
		break;
	}
	for(int i=1;i<=x;i++)
	{
		if(s[i]==R);
		B=i;
	}
	if(B%n==0)
	{
		c=B/n;
		r=n;
	}
	else if(b%n>0)
	{
		c=B/n+1;
		r=B%n;
	}
	cout<<c<<' '<<r;
	 
	
	return 0;
}
