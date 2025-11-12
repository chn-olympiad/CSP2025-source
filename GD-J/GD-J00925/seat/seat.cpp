#include<bits/stdc++.h>
using namespace std;
long long n,m,op,a[1000005],lop,x,y,zi;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	op=n*m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	lop=a[1];
	sort(a+1,a+op+1);
	for(int i=op;i>=1;i--)
	{
		if(a[i]==lop)
		{
			zi=op-i+1;
			x=zi/n;
			if(zi%n!=0)
			{
				x++;
			}
			y=zi%m;
			if(y==0)
			{
				y=m;
			}
			if(x%2==0)
			{
				y=m-y+1;
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
	
	return 0;
}
