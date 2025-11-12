#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
ll read(){
	ll ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
const ll N=1e4,M=1e6,K=10;
struct Edge{
	ll u,v,w,f;
//	bool operator <(Edge b)const
//	{
//		return w<b.w;
//	}
}e[M+5],s[N+N*K+5],ss[N+N*K+5];
ll n,m,k,ans,et;
ll bcj[N+K+5],st,sst;
bool ing[K+5];
void add1(ll u,ll v,ll w,ll f){
	e[++et].u=u;
	e[et].v=v;
	e[et].w=w;
	e[et].f=f;
	return;
}
void add2(ll u,ll v,ll w,ll f){
	s[++st].u=u;
	s[st].v=v;
	s[st].w=w;
	s[st].f=f;
	return;
}
bool cmp1(Edge a,Edge b){
	return a.w<b.w;
}
ll find(ll x){
	if(x==bcj[x])return x;
	return bcj[x]=find(bcj[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++)
	{
		ll u=read(),v=read(),w=read();
		add1(u,v,w,0);
	}
	sort(e+1,e+1+et,cmp1);
	for(ll i=1;i<=n;i++)bcj[i]=i;
	for(ll i=1;i<=et;i++)
	{
		ll u=e[i].u,v=e[i].v;
		ll uu=find(u),vv=find(v);
		if(uu==vv)continue;
		s[++st]=e[i];
		ans+=e[i].w;
		bcj[uu]=vv;
		if(st==n-1)break;
	}
	if(k==0)
	{
		printf("%lld\n",ans);
		return 0;
	}
	ing[0]=1;
	ll nn=n;
	for(ll j=1;j<=k;j++)
	{
		ll anss=read();
		for(ll i=1;i<=n;i++)
		{
			ll w=read();
			add2(n+j,i,w,j);
		}
		for(ll i=1;i<=n+j;i++)bcj[i]=i;
		nn++,ing[j]=1,sst=0;		
		sort(s+1,s+1+st,cmp1);
		for(ll i=1;i<=st;i++)
		{
			if(anss>=ans)break;
			if(ing[s[i].f]==0)continue;
			ll u=s[i].u,v=s[i].v;
			ll uu=find(u),vv=find(v);
			if(uu==vv)continue;
//			cout<<s[i].u<<" "<<s[i].v<<endl;
			ss[++sst]=s[i];
			anss+=s[i].w;
			bcj[uu]=vv;
			if(sst==nn-1)break;
		}
//		cout<<j<<" "<<anss<<endl;
		if(anss<ans)
		{
			ans=anss;
			for(ll i=1;i<=sst;i++)s[i]=ss[i];
			st=sst;
		}
		else
		{
			nn--;
			ing[j]=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
