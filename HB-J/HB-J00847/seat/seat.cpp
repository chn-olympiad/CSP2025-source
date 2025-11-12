#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int g=a[1],h;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==g)
		{
			h=n*m-i+1;
			break;
		}
	}
	if(h%m==0)
	{
		if((h/m)%2!=0)
		{
			cout<<h/m<<" "<<n;
		}
		else
		{
			cout<<h/m<<" "<<n-n+1;
		}
	}
	else
	{
		if((h/m+1)%2!=0)
		{
			cout<<h/m+1<<" "<<h%m;
		}
		else
		{
			cout<<h/m+1<<" "<<n-(h%m)+1;
		}
	}
	return 0;
}
