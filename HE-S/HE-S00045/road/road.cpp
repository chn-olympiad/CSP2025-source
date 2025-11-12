#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+50;
int c[15],a[15][N];
vector <int> vv[N];
int q[N][N];
bool ok[N];
queue <int> qq;
bool okk;
long long ans;
void dfs(int x,long long sum,int ji)
{
	if(ji>=n)
	{
		ans=min(ans,sum);
		return ;
	}
	qq.push(x);
	ok[x]=false;
	for(int i=0;i<vv[x].size();i++)
	{
		int y=vv[x][i];
		if(ok[y])
		{
			ok[y]=false;
			sum+=q[x][y];
			dfs(y,sum,ji+1);
			ok[y]=true;
			sum-=q[x][y];
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	okk=true;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vv[u].push_back(v);
		vv[v].push_back(u);
		q[u][v]=w;
		q[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			okk=false;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0)
			{
				okk=false;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ok[i]=true;
	}
	if(k==0)
	{
		ans=2147483647;
		dfs(1,0,1);
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		if(okk==true)
		{
			cout<<0<<endl;
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(ok[i]==true)
				{
					qq.push(i);
					ok[i]=false;
				}
				while(!qq.empty())
				{
					int x=qq.front();
					for(int i=0;i<vv[x].size();i++)
					{
						int y=vv[x][i];
						if(ok[y]==true)
						{
							ok[y]=false;
							qq.push(y);
						}
					}
					for(int i=1;i<=n;i++)
					{
						if(ok[i]==true)
						{
							
						}
					}
				}
			}//找出来那些路需要城镇化才能连
//true是需要城市化才能练的 
			 for(int i=1;i<=n;i++)
			 {
			 	if(ok[i]==true)
			 	{
			 		for(int j=1;j<=k;j++)
			 		{
			 			
					}
				}
			 }
		}
	}
	return 0;
}
