#include<bits/stdc++.h>
using namespace std;
int a,b,c,j,h,x,y;
int n[105];
int m[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	c=a*b;
	for(int i=0;i<c;i++)
	{
		cin>>n[i];
		m[i]=n[i];
	}
	sort(n,n+c);
	for(int i=c-1;i>=0;i--)
	{
		j+=1;
		if(n[i]==m[0])
		{
			h=j;
		}
	}
	if(h%a==0)
	{
		x=h/a;
		if(x%2==0)
		{
			y=1;
		}
		else
		{
			y=a;
		}
	}
	else
	{
		x=h/a+1;
		if(x%2==0)
		{
			y=a-h%a+1;
		}
		else
		{
			y=h%a;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
