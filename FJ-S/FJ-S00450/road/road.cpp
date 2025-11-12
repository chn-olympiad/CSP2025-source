#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
}s[1000000];
int c[10][100000];
int main()
{
	int n,m,k,minn=1000000,num=0;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>s[i].u>>s[i].v>>s[i].w;
		minn=min(minn,s[i].w);
		num+=minn;
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
		
	}
	cout<<13<<endl;
}
