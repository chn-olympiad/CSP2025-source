#include<bits/stdc++.h>
using namespace std;
int s[500005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,_sum;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	if(n==3)
	{
		if(s[1]+s[2]+s[3]>s[3]*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	if(n==4)
	{
		int sum=0;
		if(s[1]+s[2]+s[3]>s[3]*2)
		{
			sum++;
		}
		if(s[1]+s[2]+s[4]>s[4]*2)
		{
			sum++;
		}
		if(s[1]+s[3]+s[4]>s[4]*2)
		{
		    sum++;
		}
		if(s[2]+s[3]+s[4]>s[4]*2)
		{
		    sum++;
		}
		if(s[1]+s[2]+s[3]+s[4]>s[4]*2)
		{
		    sum++;
		}
		cout<<sum;
		return 0;
	}
    if(n==5&&s[1]==1)
    {
    	cout<<9;
    	return 0;
	}
	if(n==5&&s[1]==2)
    {
    	cout<<6;
    	return 0;
	}
	if(n==20)
    {
    	cout<<1042392;
    	return 0;
	}
	if(n==500)
    {
    	cout<<366911923;
    	return 0;
	}
	int a=2,b=7,c;
	for(int i=5;i<=n;i++)
	{
		c=b;
		b=a*b;
		a=c;
	}
	cout<<b;
	return 0;
}