#include<bits/stdc++.h>
using namespace std;



int maxn=100050,t,n,dis[100050][5],ans;
void dfs(int time,int sum,int a,int b,int c)
{
	
	if(time>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(a<n/2) dfs(time+1,sum+dis[time][1],a+1,b,c);
	if(b<n/2) dfs(time+1,sum+dis[time][2],a,b+1,c);
	if(c<n/2) dfs(time+1,sum+dis[time][3],a,b,c+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int T=0;T<t;T++)
	{
		ans=0;
		memset(dis,0,sizeof(dis));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>dis[i][j];
			}
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
