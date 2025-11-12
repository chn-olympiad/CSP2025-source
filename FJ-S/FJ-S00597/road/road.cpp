#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n=0,m=0,k=0,x=0,y=0,a[10005]={};
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long v1=0,v2=0,w=0;
		cin>>v1>>v2>>w;
		x+=w;
	}
	for(int i=1;i<=k;i++)
	{
		long long q=0;
		for(int j=1;j<=(n+1);j++)
		{
			cin>>q;
			y+=q;
		}
		a[i]=q;
	}
	long long ans=0;
	for(int i=1;i<=k;i++)
	{
		if(x<=a[i])
		{
			ans=x;
		}else if(x>a[i])
		{
			ans=a[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

