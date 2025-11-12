#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,k,l,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			k=n*m-i+1;
			break;
		}
	}
	if(k%n==0)
	{
		l=k/n;
		if(l%2==0)
		{
			h=1;
		}
		else
		{
			h=n;
		}
	}
	else
	{
		l=k/n;
		l++;
		h=k%n;
		if(l%2==0)
		{
			h=n-h+1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}

