#include<bits\stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int fa[20005],c[20][10005],b[1000005][3],cc[20];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
int ans;
int find(int x)
{
	if(fa[x]==x)
		return fa[x];
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>b[i][0]>>b[i][1]>>b[i][2];
	for(int i=1;i<=k;i++)
	{
		cin>>cc[i];
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	ans=1e18;
	for(int kk=0;kk<pow(2,k);kk++)
	{
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		while(q.size()) q.pop();
		int res=0;
		int ci=n-1;
		for(int i=1;i<=m;i++)
			q.push({b[i][2],{b[i][0],b[i][1]}});
		for(int i=1;i<=k;i++)
		{
			if((1<<(i-1))&kk)
			{
				ci++;
				res+=cc[i];
				for(int j=1;j<=n;j++)
					q.push({c[i][j],{n+i,j}});
			}
		}
		while(ci)
		{
			int v=q.top().first,a=q.top().second.first,b=q.top().second.second;
			q.pop();
			if(find(a)==find(b)) continue;
			fa[find(a)]=find(b);
//			cout<<a<<" "<<b<<" "<<v<<endl;
			res+=v;
			ci--;
		}
//		cout<<res<<endl;
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
