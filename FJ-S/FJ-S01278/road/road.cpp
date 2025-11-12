#include<bits/stdc++.h>
using namespace std;
int main()
{
	int  ch[1000000+5][1000000+5],ma[1000000+5][1000000+1],w[1000000+5],rew[1000000+5];
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ch[a][b]=1;
		ma[a][b]=c;
	}
	int ans=0;
	w[1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ch[i][j]=1&&w[j]!=1)
			{
				ans+=ma[i][j];
				w[j]=1;
				rew[j]=i;
			}
			else if(ch[i][j]==1&&w[j]==1)
			{
				if(ma[i][j]<ma[rew[j]][j])
				{
					rew[j]=i;
					ans+=ma[i][j];
					ans-=ma[rew[j]][j];
				}
			}
		}
	}
	cout<<ans;
}
