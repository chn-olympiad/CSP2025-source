#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define contain(Q,i) ((Q&(1<<(i-1)))!=0)
using namespace std;
const int maxn=2e4+114,maxm=2e6+225;
struct edge
{
	int u,v,w;int id;
	friend bool operator <(edge a,edge b)
	{
		return a.w<b.w;
	}
};
edge s[maxm*2],t[maxn*2];int c[114];int n,m,k;int a[13][maxn];
int fa[maxn];
int find(int u)
{
	return fa[u]==u?fa[u]:(fa[u]=find(fa[u]));
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	rep(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge e;
		e.u=u;e.v=v;e.w=w;e.id=0;
		s[i]=e;
	}
	rep(i,1,k)
	{
		cin>>c[i];
		rep(j,1,n)
		{
			cin>>a[i][j];
		}
	}
	rep(i,1,n) fa[i]=i;
	sort(s+1,s+m+1);
	int cnt=0;
	ll ans,sum;
	ans=0;
	rep(i,1,m)
	{
		int fu,fv,u,v;
		u=s[i].u;v=s[i].v;
		fu=find(u);fv=find(v);
		if(fu!=fv)
		{
			fa[fu]=fv;cnt++;
			t[cnt]=s[i];
			ans+=s[i].w;
		}
	}
	memset(s,0,sizeof(s));
	rep(S,1,(1<<k)-1)
	{
		int d=0;
		sum=0;
		rep(i,1,n-1) s[i]=t[i];
		rep(j,1,k)
		{
			if(contain(S,j))
			{
				rep(i,1,n)
				{
					s[i+n+d*n-1].u=d+1+n;
					s[i+n+d*n-1].v=i;
					s[i+n+d*n-1].w=a[j][i];
				}
				d++;
				sum+=c[j];
			}
		}
		rep(i,1,n+d) fa[i]=i;
		sort(s+1,s+n+d*n);
		rep(i,1,n+d*n-1)
		{
			int fu,fv,u,v;
			u=s[i].u;v=s[i].v;
			fu=find(u);fv=find(v);
			if(fu!=fv)
			{
				fa[fu]=fv;
				sum+=s[i].w;
			}
		}
		ans=min(ans,sum);
		//cout<<S<<' '<<sum<<endl;
	}
	cout<<ans;
	return 0; 
}

