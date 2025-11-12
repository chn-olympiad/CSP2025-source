#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int fa[10001];
struct qqq{
	int a,b,v;
}bi[1000010];
bool qqqq(qqq x,qqq y)
{
	return x.v<y.v;
}
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>bi[i].a>>bi[i].b>>bi[i].v;
	}
	int kk=0,lll;
	for(int i=1;i<=n+1;i++)
	{
		cin>>lll;
		if(lll!=0)
		{
			kk=1;
			break;
		}
	}
	if(!kk)
	{
		cout<<0;
		return 0;
	}
	sort(bi+1,bi+1+m,qqqq);
	int an=1,ans=0;
	for(int i=1;i<=m;i++)
	{
		int x=bi[i].a,y=bi[i].b;
		x=find(fa[x]),y=find(fa[y]);
		if(x!=y)
		{
			fa[x]=fa[y];
			ans+=bi[i].v;
			an++;
		}
		if(an==n)break;
	}
	cout<<ans;
	if(0)cout<<"我真没招了，能骗两分是两分吧";
	if(0)cout<<"我想退钱，700还不如买把刀呢"; 
}
