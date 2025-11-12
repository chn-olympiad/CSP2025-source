#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		flag[a][b]=c;
		flag[b][a]=c;
		
	}
	for(int 1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			if(j==1)
			{
				cin>>build(j+n);
			}
			else
			{
				cin>>flag[n+j][n];
				flag[n+j][n]=flag[n+j][n];
			}
		}
	}
	for(int v=1;v<=n+k)
	{
		for(int i=1;i<=n+k)
		{
			for(int j=1;j<=n+k)
			{
				if(flag[i][k]>0&&flag[k][j]>0)
			}
	}
	return 0;
}