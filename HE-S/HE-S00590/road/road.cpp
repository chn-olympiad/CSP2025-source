#include <bits/stdc++.h>
using namespace std;
int p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,p=-1;
	cin>>n>>m>>k;
	int road[m+5][3];
	int coun[k+5][n+5];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>road[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>road[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(p>road[i][1])
		{
			p=road[i][1];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
