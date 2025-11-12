#include<bits/stdc++.h>
using namespace std;
int n,t,x,y,z,a,b,c,l,r,o,ans;
bool vis[100010];
struct node
{
	int f,id,b;
	friend const operator < (node a,node b)
	{
		return a.f<b.f;
	}
};
priority_queue<node>q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		a=0,b=0,c=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			q.push({x,i,1});
			q.push({y,i,2});
			q.push({z,i,3});
		}
		while(!q.empty())
		{
			l=q.top().f;
			r=q.top().id;
			o=q.top().b;
			q.pop();
			if(o==1&&a<n/2&&!vis[r])
			{
				vis[r]=1;
				a++;
				ans+=l;
			}
			if(o==2&&b<n/2&&!vis[r])
			{
				vis[r]=1;
				b++;
				ans+=l;
			}
			if(o==3&&c<n/2&&!vis[r])
			{
				vis[r]=1;
				c++;
				ans+=l;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}