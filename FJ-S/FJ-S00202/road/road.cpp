#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,fa[10005],cnt;
long long ans;
int find_fa(int i)
{
	if(fa[i]==i)
		return i;
	fa[i]=find_fa(fa[i]);
	return fa[i];
}
struct path
{
	int u,v,w;
	const bool operator<(const path &o)const
	{
		return w<o.w;
	} 
}r[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=m;i++)
			cin>>r[i].u>>r[i].v>>r[i].w;
		sort(r+1,r+m+1);
		cnt=n;
		for(int i=1;i<=m;i++)
		{
			if(find_fa(r[i].u)!=find_fa(r[i].v))
			{
				fa[find_fa(r[i].u)]=find_fa(r[i].v);
				cnt--;
				ans+=r[i].w;
			}
			if(cnt==1)
				break;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
//use cin&&cout!!!
