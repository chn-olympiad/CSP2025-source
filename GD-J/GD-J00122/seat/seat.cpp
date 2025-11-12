#include<bits/stdc++.h>
using namespace std;
long long a[1000000+5],k,n,m,t,p,q;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==k)
		{
			t=n*m-i+1;
			break; 
		}
	}

	if(t%n==0)
	p=t/n;
	else
	p=t/n+1;
	if(p%2==1)
	{
		cout<<p<<" "<<t-(p-1)*n;
	}
	else
	{
		cout<<p<<" "<<p*n-t+1;
	}
	return 0;
}
