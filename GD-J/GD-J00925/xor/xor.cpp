#include<bits/stdc++.h>
using namespace std;
long long n,u,a[1000005],qw,l,r[1000005],tol,zu,xf,yf,df;
long long top(long long x,long long y)
{
	tol=max(x,y);
	zu=1;
	df=0;
	while(tol>0)
	{
		xf=x%2;
		yf=y%2;
		if(xf!=yf)
		{
			df+=zu;
		}
		x/=2;
		y/=2;
		zu*=2;
		tol/=2;
	}
	return df;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>u;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==u)
		{
			qw++;
			l=0;
			continue;
		}
		if(l==0)
		{
			l++;
			r[l]=a[i];
		}
		else
		{
			for(int j=1;j<=l;j++)
			{
				r[j]=top(r[j],a[i]);
				if(r[j]==u)
				{
					qw++;
					l=0;
					break;
				}
			}
		}
	}
	cout<<qw;
	
	return 0;
} 
