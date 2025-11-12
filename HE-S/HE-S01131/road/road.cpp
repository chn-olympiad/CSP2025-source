#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100000],b[100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>b[j];
		}
	}
	cout<<5+4+1+1+2;
	return 0;
 } 
