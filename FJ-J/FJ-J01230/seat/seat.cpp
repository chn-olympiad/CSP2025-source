#include<bits/stdc++.h>
using namespace std;
int n,m,a,l,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>l;
	a=0;
	for(int i=2;i<=n*m;i++)
	{
		cin>>p;
		if(p>l)
		{
			a++;
		}
	}
	cout<<a/n+1<<" ";
	if((a/n+1)%2==1)
	{
		cout<<1+(a%n);
	}
	else
	{
		cout<<n-(a%n);
	}
}
