#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=n*m;
	int q[a+1];
	for(int i=1;i<=a;i++)
	{
		cin>>q[i];
	}
	int o=q[1];
	sort(q+1,q+a+1);
	int w;
	for(int i=1;i<=a;i++)
	{
		if(o==q[i])
		{
			w=a-i+1;
			break;	
		}
	}
	int r=w%n;
	if(r==0)
	{
		int c=w/n;
		if(c%2==0)
		{
			cout<<c<<' '<<1;
		}
		else
		{
			cout<<c<<' '<<n;
		}
	}
	else
	{
		int c=w/n+1;
		if(c%2==0)
		{
			cout<<c<<' '<<n-w%n+1;
		}
		else
		{
			cout<<c<<' '<<w%n;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
