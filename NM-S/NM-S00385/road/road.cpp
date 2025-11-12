#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct ui
{
	int l,r,w;
}road[1001001];
int city[1001][1001];
int pd[1001][1001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>road[i].l>>road[i].r>>road[i].w;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++)
			cin>>city[i][j];
	int num=0;
	for(int i=1;i<=m;i++)
	{
		if(pd[road[i].l][road[i].r]==0||pd[road[i].r][road[i].l]==0)
		{
			pd[road[i].l][road[i].r]=road[i].w;
			pd[road[i].r][road[i].l]=road[i].w;
			num+=road[i].w;
			num++;
		}
		else if(road[i].w<pd[road[i].l][road[i].r])
		{
			num-=pd[road[i].l][road[i].r]-road[i].w;
			pd[road[i].l][road[i].r]=road[i].w;
		}
	}
	cout<<num;
	return 0;
}
