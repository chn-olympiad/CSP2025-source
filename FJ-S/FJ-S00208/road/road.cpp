#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
#define Hoshino 520520520520ll
inline void write(ll x)
{
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline ll read()
{
	ll x=0;bool c=0;char a=getchar();
	for(;a<'0'||a>'9';a=getchar())c|=a==45;
	for(;a>='0'&&a<='9';a=getchar())x=(x<<3)+(x<<1)+(a^48);
	return c?-x:x;
}
#define R read()
using namespace std;

ll n,m,k,ans=Hoshino;
ll c[12],a[12][20002],d[20002],f[20002];
bool vis[20002];
ll cnt=0,ct=0,head[20002];
struct Edge
{
	ll nxt,frm,to,w,id;
}e[4000002],e_[200002];
inline bool cmp(Edge A,Edge B){return A.w<B.w;}
inline void Add(ll u,ll v,ll w,ll id)
{
	e[++cnt].nxt=head[u];
	e[cnt].frm=u;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].id=id;
	head[u]=cnt;
}
inline void Add_(ll u,ll v,ll w,ll id)
{
	e_[++ct].frm=u;
	e_[ct].to=v;
	e_[ct].w=w;
	e_[ct].id=id;
}
inline ll Prim(ll num)
{
	for(ll i=1;i<=n+100;++i)vis[i]=0,d[i]=Hoshino;
	ll ret=0;
	priority_queue<pair<ll,ll> >q;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		pair<ll,ll>x=q.top();
		q.pop();
//		cout<<x.second<<"  "<<x.first<<endl;
		if(vis[e[x.second].to])continue;
		Add_(e[x.second].frm,e[x.second].to,e[x.second].w,e[x.second].id);
		ret-=x.first;
		vis[e[x.second].to]=1;
		for(ll i=head[e[x.second].to];i;i=e[i].nxt)if(e[i].id&num)
		{
//			cout<<"Check "<<x.second<<" to "<<e[i].to<<endl;
			if(!vis[e[i].to]&&e[i].w<d[e[i].to])
				d[e[i].to]=e[i].w,
				q.push(make_pair(-e[i].w,i));
		}
	}
	return ret;
}
inline ll GF(ll x){return f[x]==x?x:f[x]=GF(f[x]);}
inline ll Kruskal(ll N,ll num)
{
	ll ret=0;
	for(ll i=1;i<=n+k;++i)f[i]=i;
	for(ll i=1,j=1;i<N;++i)
	{
		ll fx,fy;
		for(;j<=ct;++j)
		{
//			cout<<e_[j].id<<endl;
			if((e_[j].id&num))
			{
//				cout<<e_[j].frm<<"  "<<e_[j].to<<endl;
				fx=GF(e_[j].frm),fy=GF(e_[j].to);
				if(fx!=fy)break;
			}
		}
		f[fx]=fy;
		ret+=e_[j].w;
	}
	return ret;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=R,m=R,k=R;
	for(ll i=1;i<=m;++i)
	{
		ll x=R,y=R,w=R;
		Add(x,y,w,(1<<(k+1))-1);
		Add(y,x,w,(1<<(k+1))-1);
	}
	ans=Prim(1);
//	cout<<ans<<endl;
	for(ll i=1;i<=k;++i)
	{
		c[i]=R;
		for(ll j=1;j<=n;++j)
		{
			a[i][j]=R;
			Add_(n+i,j,a[i][j],(1<<(i-1)));
//			Add_(j,n+i,a[i][j],(1<<(i-1)));
		}
	}
//	cout<<ct<<endl;
	sort(e_+1,e_+1+ct,cmp);
	for(ll i=1;i<=(1<<k)-1;++i)
	{
		ll sum=0,kkk=0;
		for(ll j=0;j<k;++j)if(((i>>j)&1))++kkk,sum+=c[j+1];
		if(sum>=ans)continue;
		sum+=Kruskal(n+kkk,i);
//		cout<<sum<<"---"<<i<<endl;
		ans=min(ans,sum);
	}
	write(ans);
	return 0;
}
