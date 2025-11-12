#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int grade;
int nm;
int num;
int g;
int c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	nm=2*n;
	for(int i=1;i<=num;i++)
	{
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+1+num);
	for(int i=num;i>=1;i--)
	{
		grade++;
		if(a[i]==g)
		{
			break;
		}
	}
	c=grade/nm*2;
	r=grade%nm;
	if(r==0)
	{
		cout<<c<<" "<<1;
		return 0;
	}
	if(r>n)
	{
		cout<<c+2<<" "<<nm-r+1;
	}
	else
	{
		cout<<c+1<<" "<<r;
	}
	return 0;
}
