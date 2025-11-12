#include<iostream>
using namespace std;
int n,m,k,ans;
int next[10010][10100];
int u,v,w,c[10010],tmp,tmp2=9999999;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=1;i<=m;i++) cin >>u>>v>>w,next[u][v]=w,next[v][u]=w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[n+i];
		for(int j=1;j<=n;j++) cin >>w,next[j][n+i]=w;
	}
	for(int i=1;i<=n;i++)
	{
		tmp2=999999;
		for(int j=1;j<=(n+k);j++)
		{
			if(tmp2>=(next[i][j]+c[j]) and next[i][j]!=0)
			{
				tmp2=(next[i][j]+c[j]);
				tmp=j;
			}
		}
		ans+=tmp2;
		if(n<tmp) c[tmp]=0;
	}
	cout <<ans;
}
