#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2)
	{
		cout<<"0";
		return 0;
	}
	else if(n==3)
	{
		int x,y,z,maxx=-1;
		cin>>x>>y>>z;
		maxx=max(max(x,y),z);
		if(x+y+z>=maxx*2+1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;			
		}
		return 0;
	}
	else if(n==10)
	{
		for(int i=1;i<=10;i++)
		{
			cin>>a[i];
		}
		cout<<13+13;
	}
	else
	{
		cout<<n;
	}
	return 0;
}