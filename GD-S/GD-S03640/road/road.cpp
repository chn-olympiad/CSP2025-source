#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
const int M=1e6+5;
ll n,m,k,c[15],cc[15][N],f[N],ff[N],ans,sum,cnt,cntb;
bool vis[M];
bool is_son[1005][1005];
struct st
{
	ll u,v,w;
}a[M],bian[N];
struct data
{
	ll nxt,val;
};
vector<data> e[N];
bool cmp(st x,st y)
{
	return x.w<y.w;
}
ll find(ll x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void Kruskal()//跑最小生成树
{
	for(int i=1;i<=m;i++)
	{
		ll fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy)
		{
			cnt++;
			ans+=a[i].w;
			f[fx]=fy;
			vis[i]=true;
			if(cnt==n-1) return ;
		}
	}
}
void dfs(ll u,ll fa)
{
	ff[u]=fa;
	for(int i=0;i<e[u].size();i++)
	{
		ll v=e[u][i].nxt;
		if(fa==v) continue;
		dfs(v,u);
		for(int j=1;j<=n;j++)
		{
			if(is_son[v][j]==true) is_son[u][j]=true;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&cc[i][j]);
		}
	}
	Kruskal();
	sum=ans;
	if(k==0)//Subtask1,2,3,4 16pts
	{
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(vis[i]==false) continue;
		bian[++cntb]=(st){a[i].u,a[i].v,a[i].w};
		//e[a[i].u].push_back((data){a[i].v,a[i].w});
		//e[a[i].v].push_back((data){a[i].u,a[i].w});
	}
	/*dfs(1,0);
	for(int S=0;S<(1<<k);S++)
	{
		ll tmp=sum;
		for(int i=1;i<=k;i++)
		{
			if((S&(1<<(i-1)))) tmp+=c[i];
		}
		for(int i=1;i<=cntb;i++)
		{
			ll val=-1;
			for(int j=1;j<=k;j++)
			{
				for(int w=1;w<=n;w++)
				{
					if(ff[bian[i].u]==bian[i].v)
					{
						if(is_son[bian[i].v][w]==true)
						{
							val=max(val,bian[i].w-cc[j][w]-cc[j][bian[i].v]);
						}
						if(is_son[bian[i].u][w]==false)
						{
							val=max(val,bian[i].w-cc[j][w]-cc[j][bian[i].u]);
						}
					}
					else
					{
						if(is_son[bian[i].u][w]==true)
						{
							val=max(val,bian[i].w-cc[j][w]-cc[j][bian[i].u]);
						}
						if(is_son[bian[i].v][w]==false)
						{
							val=max(val,bian[i].w-cc[j][w]-cc[j][bian[i].v]);
						}
					}
				}
			}
			if(val>=0) tmp-=val;
		}
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);*/
	/*for(int i=1;i<=cntb;i++)
	{
		cout<<bian[i].u<<" "<<bian[i].v<<" "<<bian[i].w<<endl;
	}*/
	for(int S=0;S<(1<<k);S++)
	{
		ll tmp=sum;
		for(int i=1;i<=k;i++)
		{
			if(S&(1<<(i-1))) tmp+=c[i];
		}
		//cout<<S<<" "<<tmp<<endl;
		for(int i=1;i<=cntb;i++)
		{
			ll val=-1;
			for(int j=1;j<=k;j++)
			{
				if((S&(1<<(j-1)))==0) continue;
				//val=max(val,bian[i].w-cc[j][bian[i].u]-cc[j][bian[i].v]);
				//cout<<j<<" "<<val<<endl;
				tmp=min(tmp,tmp-bian[i].w+cc[j][bian[i].u]+cc[j][bian[i].v]);
			}
			/*if(val>=0)
			{
				tmp-=val;
				
			}*/
		}
		ans=min(ans,tmp);
		//cout<<S<<" "<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
