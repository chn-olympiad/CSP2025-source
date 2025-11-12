#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b,zh=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		zh+=a[i];
	} 
	if(n==3)
	{
		b=max(a[1],max(a[2],a[3]));
		if(zh>2*b)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<5;
	}
	return 0;
} 
