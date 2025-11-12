#include<bits/stdc++.h>
#define int unsigned long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int T,n,m,k,x,y,z,cnt;
int ans;
bool flag=1;
int f[10005];
int t[15];
int c[10005];
int a[10005];
int mp[1005][1005];
int fr[1005][1005];
struct Edge{int u,v,w,fr;};
vector<Edge> v;
int find(int x)
{
	return f[x]=(f[x]==x?x:find(f[x]));
}
bool cmp(Edge x,Edge y){return x.w<y.w;}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,memset(mp,127,sizeof mp);
	rep(i,1,n) f[i]=i;
	rep(i,1,m) cin>>x>>y>>z,v.push_back({x,y,z,0});
	rep(i,1,k)
	{
		cin>>c[i],flag=min(flag,c[i]==0);
		rep(j,1,n) cin>>a[j];
		rep(j,1,n) rep(l,j+1,n) 
		{
			// if(j==1&&l==3) cout<<a[j]<<" "<<a[l]<<" "<<c[i]<<"\n";
			if(mp[j][l]>a[j]+a[l]+c[i])
			{
				mp[j][l]=min(mp[j][l],a[j]+a[l]+c[i]);	
				fr[j][l]=i;
			}
		}
	}
	rek(i,1,n) rep(j,i+1,n) v.push_back({i,j,mp[i][j],fr[i][j]});
	if(k==0||flag)
	{
		sort(v.begin(),v.end(),cmp);
		for(auto e:v)
		{
			int u=e.u,v=e.v;
			int fu=find(u),fv=find(v);
			if(fu!=fv) f[fu]=fv,cnt++,ans+=e.w;//,cout<<u<<" "<<v<<" "<<e.w<<"\n";
			if(cnt==n-1) break;
		}
		return cout<<ans,0;
	}
	else
	{
		sort(v.begin(),v.end(),cmp);
		for(auto e:v)
		{
			int u=e.u,v=e.v;
			int fu=find(u),fv=find(v);
			// if(u==1&&v==3) cout<<e.w<<"\n\n\n";
			if(fu!=fv&&cnt<n) f[fu]=fv,cnt++,ans+=e.w,t[e.fr]++;//cout<<u<<" "<<v<<" "<<e.w<<"\n";
			// if(cnt==n-1) break;
		}
		rep(i,1,k) if(t[i]) ans-=(t[i]-1)*c[i];
		return cout<<ans,0;
	}
}