#include<bits/stdc++.h>
using namespace std;
//ji de shan zu shi;
const int N=1e6+50;
int n,m,k;
int w[5500][5000];
bool ok[N];
vector<int> a[N];
queue<int> q;
long long ans=21474836470;
//ji de shan zu shi;
void dfs(int x,int y,long long cnt)
{
	if(y==n&&cnt!=0)
	{
		//cout<<cnt<<endl;
		ans=min(ans,cnt);
		//cout<<ans<<endl;
	}
	ok[x]=true;
	for(int i=0;i<a[x].size();i++)
	{
		if(ok[a[x][i]]==false)
		{
			//cout<<w[x][a[x][i]]<<endl;
			dfs(a[x][i],y+1,cnt+w[x][a[x][i]]);
			ok[a[x][i]]==true;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ji de shan zu shi;
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int u=0,v=0;
			cin>>u>>v;
			cin>>w[u][v];
			//cout<<w[u][v]<<endl;
			w[v][u]=w[u][v];
			a[u].push_back(v);
			a[v].push_back(u);
		}
		long long letai=21474836470;
		for(int i=1;i<=n;i++)
		{
			ans=21474836470;
			dfs(i,1,0);
			//cout<<ans<<endl;
			for(int i=1;i<=n;i++)
			{
				if(ok[i]==true)
				{
					ok[i]=false;
				}
				else
				{
					ans=21474836470;
				}
			}
			
			letai=min(letai,ans);
			//cout<<ans<<endl;
		}
		cout<<letai<<endl;
	}
	//ji de shan zu shi;
	
	return 0;
}
