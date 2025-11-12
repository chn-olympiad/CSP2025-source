#include<bits/stdc++.h>
using namespace std;
int n,m,k,visu[1010],countryside;
struct Node
{
	bool vis=0;
	int w=0x3f3f3f;
}mp[1010][1010];
struct countryside
{
	bool vis=0;
	int a[1010],w;
}c[15];
int checkcountryside(int u,int v)
{
	int ans=0x3f3f3f3f;
	for(int i=1;i<=k;i++)
	{
		if(c[i].vis==0)
		{
			if(c[i].a[u]+c[i].a[v]+c[i].w<ans)
			{
				ans=c[i].a[u]+c[i].a[v]+c[i].w;
				countryside=i;
			}
		}
		else
		{
			if(c[i].a[u]+c[i].a[v]<ans)
			{
				ans=c[i].a[u]+c[i].a[v];
				//countryside=i;
			}
		}
	}
	if(countryside==0)return ans;
	else return -ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		mp[u][v].w=w;
		mp[v][u].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i].w;
		for(int j=1;j<=n;j++)
		{
			cin>>c[i].a[j];
		}
	}
	for(int i=1,v=0,isc=0,check;i<=n;i++)
	{
		check=0x3f3f3f,isc=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(mp[i][j].vis==1||mp[j][i].vis==1)continue;
			check=checkcountryside(i,j);
			if(mp[i][j].w<mp[i][v].w)
			{
				v=j;
				isc=0;
			}
			
			if(check<=mp[i][v].w&&check<0)
			{
				check=-check;
				isc=1;
			}
			else isc=0,check=0x3f3f3f;
		}
		if(isc==1)
		{
			c[countryside].vis=1;
			ans+=check;
			//cout<<"countryside:"<<countryside<<endl;
			//cout<<"check:"<<check<<endl;
		}
		else if(mp[i][v].vis==0&&mp[v][i].vis==0)
		{
			mp[i][v].vis=1,mp[v][i].vis=1;
			ans+=mp[i][v].w;
			//cout<<"mp:"<<i<<" "<<v<<endl;
		}
	}
	//cout<<ans;
	return 0;
}
