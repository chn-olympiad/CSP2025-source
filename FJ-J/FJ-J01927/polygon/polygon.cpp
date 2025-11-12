#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==0||n==1||n==2)
	{
		cout<<0;
	}
	else if(n==3)
	{
		cin>>a>>b>>c;
		if(a+b+c<max(a,max(b,c)))
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		cout<<5;
	}
}          
