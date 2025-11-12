#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	freopen("stdin.seat","r",stdin);
	freopen("stdout.seat","w",stdout);
	int n,m,a[1000]={0};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int laoR=a[1];
	int x=1;
	bool flag=false;
	for(int i=1;i<n*m;i++)
	{
		for(int j=1;j<n*m;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				if(laoR==a[x])
				{
					cout<<i<<" "<<j;
					flag=true;
					break;
				}
				x++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(laoR==a[x])
				{
					cout<<i<<" "<<j;
					flag=true;
					break;
				}
				x++;
			}
		}
		if(flag)
		{
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
