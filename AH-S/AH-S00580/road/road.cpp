#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,to,val;
}mp[1000010];
int tot,fa[10010],c[20],o[10010];
int n,m,k;
bool cmp(node a,node y)
{
	return a.val<y.val;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kkk(int x)
{
	int tot=0;
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		if(tot==n-1)
		{
			cout<<ans;
			return ;
		}
		int fa1=find(mp[i].x),fa2=find(mp[i].to);
		if(fa1!=fa2)
		{
			tot++;
			ans+=mp[i].val;
			fa[fa1]=fa[fa2];
		}
	}
	return ;
}
int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		mp[i].x=x,mp[i].to=y,mp[i].val=z;
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=k;i++) 
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>o[i];
		}
	}
	sort(mp+1,mp+m+1,cmp);	
	kkk(1);
	return 0;
}
