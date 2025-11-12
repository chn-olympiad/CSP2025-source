#include<bits/stdc++.h>
using namespace std;
int a,s=1,a1,b,n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>a;
		if(a>a1)
		{
			s++;
		}
	}
	if(s%n!=0)
	{
		b=s/n+1;
	}else
	{
		b=s/n;
	}
	cout<<b<<' ';
	if(b%2==1)
	{
		cout<<s-(b-1)*n;
	}else
	{
		cout<<n-(s-(b-1)*n)+1;
	}
}

