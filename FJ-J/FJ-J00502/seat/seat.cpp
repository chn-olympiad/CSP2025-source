#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,r=1,s[15][15],a[110],b,rc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
	}
	rc=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;--i)
	{
		if(a[i]==rc)
		{
			cout<<c<<" "<<r;
			break;
		}
		s[r][c]=a[i];
		if(b==0&&r+1<=n)
		{
			r++;
		}
		else if(b==0&&r==n)
		{
			c++;
			b=1;
		}
		else if(b==1&&r-1>=1)
		{
			r--;
		}
		else if(b==1&&r==1)
		{
			c++;
			b=0;
		}
	}
	return 0;
}
