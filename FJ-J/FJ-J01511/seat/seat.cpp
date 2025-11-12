#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;cin>>n>>m;
	int b[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	int r=b[0],dsa;sort(b,b+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(b[i]==r)
		{
			dsa=i;
		}
	}
	int ps=n*m-1;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				if(dsa==ps)
				{
					cout<<i<<" "<<j;return 0;
				}ps-=1;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(dsa==ps)
				{
					cout<<i<<" "<<j;return 0;
				}ps-=1;
			}
		}
	}
}
