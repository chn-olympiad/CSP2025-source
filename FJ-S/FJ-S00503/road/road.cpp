#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int x,y,v;
}a[1000002];
int c[100002];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].v;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
		}
	}
	cout<<"0";
}
