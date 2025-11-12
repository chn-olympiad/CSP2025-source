#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
vector< vector<pair<int ,int > > > gr(N);
int n,m,k;long long ans=INT_MAX;
int c[11],a[11][10001];
bool vd[10001]={false};
inline void tr(int s,int c,int d)
{
	if(d>=ans)
	return ;
	if(c==n)
	{
		ans=fmin(ans,d);
		return ;
	}
	for(const auto& u : gr[s])
	{
		int  w=u.first;
		int  v=u.second;
		if(!vd[v])
		{       
			vd[v]=true;
			tr(v,c+1,d+w);
			vd[v]=false;
		}   
	}    
}     
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		gr[u].push_back(make_pair(w,v));
		gr[v].push_back(make_pair(w,u));
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",a[i][j]);
			gr[a[i][j]].push_back(make_pair(a[i][j],j));
		}
	}
	vd[1]=true;
	tr(1,1,0);
	printf("%lld",ans);
	return 0;
}
