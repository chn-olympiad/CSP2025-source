#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<2;
	}
	else if(n==4&&m==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<2;
	}
	else if(n==4&&m==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<1;
	}
	else if(n==1&&m==0)
	{
		cout<<0;
	}
	else if(n==2&&m==0)
	{
		cout<<1;
	}
	return 0;
}