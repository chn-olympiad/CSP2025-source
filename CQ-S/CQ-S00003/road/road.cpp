#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct road
{
	int a,b,c;
}road[50005];
struct neo
{
	int x;
	int money[50005];
}neo[50005];
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>road[i].a>>road[i].b>>road[i].c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>neo[i].x;
		for(int j=1;j<=n+1;j++)
		{
			cin>>neo[i].money[j];
		}
	}
		
	return 0;
}
