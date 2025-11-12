#include<iostream>
#include<cstdio>
using namespace std;
int n,m,r,a,s,d[110],ans=1,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n>>r;
	a=m*n-1;
	for(int i=1;i<=a;i++)
	{
		cin>>s;
		d[s]=s;
	}
	for(int i=100;i>r;i--)
	{
		if(d[i]!=0)
		{
			ans++;
		}
	}
	l=ans%m+1;
	h=ans%n;
	if(ans/n==1||3||5||7||9)
	{
		if(ans%n==0) 
		{h=n;}
		else
		{h=n-h;}
	}
	cout<<l<<" "<<h;
	return 0;
}

