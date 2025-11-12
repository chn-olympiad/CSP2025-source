#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	int n,m,c,x,k;
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+c+1);
	for(int i=1;i<=c;i++)
	{
		if(a[i]==x)
		{
			k=c-i+1;
			if(k%m==0)
			{
				l=k/m;
			}
			else
			{
				l=k/m+1;
			}
			cout<<l;
			h=k-(l-1)*m;
			if(l%2==0)
			{
				h=m-h+1;	
			}
			cout<<" "<<h;
		}
	}
	return 0;
}
