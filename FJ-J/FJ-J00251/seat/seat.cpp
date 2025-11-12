#include<bits/stdc++.h>
using namespace std;
int seat[400];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	for(int i=0;i<nm;i++)
	{
		cin>>seat[i];
	}
	int a=seat[0];
	sort(seat,seat+nm);
	for(int i=0;i<nm;i++)
	{
		if(seat[i]==a)
		{
			a=nm-i;
			break;
		}
	}
	int b=a/n,c=a%n;
	if(b*n==a)
	{
		
		if(b%2)
		{
			cout<<b<<' '<<n;
		}
		else
		{
			cout<<b<<' '<<1;
		}
	}
	else
	{
		b+=1;
		if(b%2)
		{
			cout<<b<<' '<<c;
		}
		else
		{
			cout<<b<<' '<<n-c+1;
		}
	}
	return 0;
} 
