#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long n,m,a[100000],zong,b;
int A(int k,int l)
{
	return k>l;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	long long o=n*m;
	for(int z=1;z<=o;z++)
	{
		cin>>a[z];
	}
	zong=a[1];
	sort(a+1,a+o+1,A);
	for(int z=1;z<=o;z++)
	{
		if(a[z]==zong)
		{
			b=z;
			break;
		}
	}
	long long s=0,x=1,y=0;
	while(s!=b)
	{
		s++;
		if(y==n)
		{
			y=1;
			x++;
		}
		else
		{
			y++;
		}
	}
	if(x%2==0)
	{
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
