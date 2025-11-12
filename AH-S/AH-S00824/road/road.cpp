#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int s[10010];
int a[20][10010];
struct node{
	int u,v,w;
};
node b[1000010];

int fin(int x)
{
	if(s[x]!=x)
	{
		return s[x]=fin(s[x]);
	}
}
void marge(int x,int y)
{
	x=fin(x),y=fin(y);
	s[x]=s[y];
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
		s[i]=i;
	}
    for(int i=1;i<=m;i++)
    {
		cin>>u>>v>>w;
		b[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		int id;
		cin>>id;
		for(int i=1;i<=n;i++) cin>>a[1][i];
	}
	sort(b+1,b+n+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		u=b[i].u,v=b[i].v;
		if(s[u]==s[v]) continue;
		ans+=b[i].w;
		cnt++;
		marge(u,v);
		if(cnt==n-1) break;
 	}
 	cout<<ans;
    return 0;
}
