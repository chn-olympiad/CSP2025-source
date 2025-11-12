#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int fa[10005];
int find(int x)
{
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(vector<ll> &a,vector<ll>&b)
{
	return a[2]<b[2];
}	
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<ll>>edge(m+1,vector<ll>(3,0));
	for(int i=0;i<m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		edge[i][0]=x;
		edge[i][1]=y;
		edge[i][2]=z;
	}
	sort(edge.begin(),edge.end(),cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
    }
    int edgecnt=0;
    ll ans=0;
    for(int i=0;i<m && edgecnt<n-1;i++)
    {
		int x=edge[i][0],y=edge[i][1];
		x=find(x);
		y=find(y);
		if(x!=y)
		{
			fa[y]=x;
			edgecnt++;
			ans+=edge[i][2];
		}
	}
	cout<<ans;
	return 0;
}
