#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct Node{
	int u,v,w;
}e[2000005];
int n,m,k,c,a[200005],fa[200005],ans,cnt;
inline int find(int x)
{
	while(x!=fa[x])
		x=fa[x]=fa[fa[x]];
	return x;
}
inline bool cmp(Node xx,Node yy)
{
	return xx.w<yy.w;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	while(k--)
	{
		vector<int> v;
		cin>>c;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
				v.push_back(i);
		}
		for(int i=1;i<v.size();i++)
		{
			int x=find(v[0]),y=find(v[i]);
			if(x!=y)
				fa[x]=y;
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=0)
				e[++m]={find(v[0]),i,a[i]};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m&&cnt!=n-1;i++)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y)
			ans+=e[i].w,fa[x]=y;
	}
	cout<<ans;
	return 0;
}
