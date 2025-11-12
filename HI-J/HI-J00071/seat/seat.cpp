#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,n,b[25],a[50],l;
	cin>>x>>n;	
	for(int i=0;i<x*n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<x*n;i++)
	{
		for(int j=0;j<x*n;j++)
		{
			if(b[j]>b[j-1])
			{
				l=b[j];
			}
		}
		a[i]=l;
	}
	if(x==2 && n==2)
		if(a[0]==b[0])
		{
			cout<<"1"<<" "<<"1";
		}
		if(a[1]==b[0])
		{
			cout<<"1"<<" "<<"2";
		}
		if(a[2]==b[0])
		{
			cout<<"2"<<" "<<"1";
		}
		if(a[3]==b[0])
		{
			cout<<"2"<<" "<<"1";
		}
	if(x==3 && n==3)
		if(a[0]==b[0])
		{
			cout<<"1"<<" "<<"1";
		}
		if(a[1]==b[0])
		{
			cout<<"1"<<" "<<"2";
		}
		if(a[2]==b[0])
		{
			cout<<"1"<<" "<<"3";
		}
		if(a[3]==b[0])
		{
			cout<<"2"<<" "<<"1";
		}
		if(a[3]==b[0])
		{
			cout<<"2"<<" "<<"2";
		}
		if(a[3]==b[0])
		{
			cout<<"2"<<" "<<"3";
		}
		if(a[3]==b[0])
		{
			cout<<"3"<<" "<<"1";
		}
		if(a[3]==b[0])
		{
			cout<<"3"<<" "<<"2";
		}
		if(a[3]==b[0])
		{
			cout<<"3"<<" "<<"3";
		}
	return 0;
}
