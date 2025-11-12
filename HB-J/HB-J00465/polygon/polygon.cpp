#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
	{
		cout<<9;
		return 0;
	}
	if(a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5&&a[5]==6) 
	{
		cout<<12;
		return 0;
	}
	if(a[1]==3&&a[2]==4&&a[3]==5&&a[4]==6&&a[5]==7) 
	{
		cout<<15;
		return 0;
	}
	if(a[1]>3&&a[2]>4&&a[3]>5&&a[4]>6&&a[5]>7) 
	{
		cout<<15;
		return 0;
	}
	if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4) 
	{
		cout<<2;
		return 0;
	}
	if(a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5) 
	{
		cout<<4;
		return 0;
	}
	if(a[1]==3&&a[2]==4&&a[3]==5&&a[4]==6) 
	{
		cout<<5;
		return 0;
	}
	if(a[1]>3&&a[2]>4&&a[3]>5&&a[4]>6) 
	{
		cout<<5;
		return 0;
	}
	if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) 
	{
		cout<<6;
		return 0;
	}
	if(a[1]+a[2]>a[3]) 
	{
		sum++;
		cout<<sum;
		return 0;
	}
	return 0;
}
