#include<bits/stdc++.h>
using namespace std;
int n,m,aa,ww,bb,a[102],sum=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	aa=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		sum++;
		if(a[i]==aa)
		{
			ww=sum;
			break;
		}
	}
	if(ww<=n)
	{
		cout<<1<<" "<<ww;
		return 0;
	}
	if(ww%n==0)
	{
		bb=ww/n;
	}
	else
	{
		bb=ww/n+1;
	}
	if(bb%2==0)
	{
		cout<<bb<<" "<<n-ww%n+1;
	}
	if(bb%2!=0)
	{
		cout<<bb<<" "<<ww%n;
	}
	return 0;
}