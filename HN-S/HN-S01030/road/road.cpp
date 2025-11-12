#include<bits/stdc++.h>
using namespace std;
struct mango 
{
	int x,y,z;
};
vector<mango>v;
int p[1000005],ans=0;
int find(int x)
{
	if(x!=p[x])
	{
		return (p[x]=find(p[x]));
	}
	return x;
}
bool cmp(mango a,mango b)
{
	return a.z<b.z;
}
void mimoney()
{
	sort(v.begin(),v.end(),cmp);
	for(auto i:v)
	{
		int x=i.x,y=i.y;
		int px=find(x),py=find(y);
		if(px==py)
		{
			continue;
		}
		p[px]=py;
		ans+=i.z;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			v.push_back({i,j,x});
		}
	}
	mimoney();
	cout<<ans;
	return 0;
 } 
