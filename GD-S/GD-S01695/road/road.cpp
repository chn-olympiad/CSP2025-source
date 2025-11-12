#include<bits/stdc++.h>
using namespace std;
struct fan{
	int x,y,z;
	bool operator < (const fan&a)const{
	return z>a.z;
	}
};
priority_queue<fan> q;
long long ans,e,n,m,a,b,c,k;
int fa[1005],t[1005];
int find(int x)
{
	if (x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
void unf(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		q.push({a,b,c});
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c;
		for (int j=1;j<=n;j++)
		{
			cin>>t[j];
			for (int g=1;g<j;g++)
			{
			    //cout<<t[g]<<" "<<t[j]<<"\n";
			    q.push({g,j,t[g]+t[j]});
			}
		}
	}
	while (!q.empty())
	{
		//cout<<q.top().z<<"\n";
		if (find(q.top().x)!=find(q.top().y))
		{
			ans+=q.top().z;
			unf(q.top().x,q.top().y);
		}
		q.pop();
	}
	cout<<ans;
	return 0;
 } 
