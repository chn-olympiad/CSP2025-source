#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=1100010,N=15,K=10010;
ll n,m,k,c[N][K],nxt[N],fl,f[K],s,x,y,t,p,o,now,d,tmp;
struct node{ll x,y,z;}a[M],b[M];
ll cmp(node x,node y){return x.z<y.z;}
ll find(ll x){if(f[x]!=x)f[x]=find(f[x]);return f[x];}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(register ll i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(register ll i=1;i<=k;++i)
	{
		cin>>c[i][0];
		tmp=0;
		for(register ll j=1;j<=n;++j)
		{
			cin>>c[i][j];
			if(!c[i][j])tmp=1,nxt[i]=j;
		}
		if(c[i][0]||!tmp)fl=1;
	}
	if(!fl)
	{
		for(register ll i=1;i<=k;++i)
		{
			for(register ll j=1;j<=n;++j)
				a[++m]={nxt[i],j,c[i][j]};
		}
		s=t=0;
		sort(a+1,a+m+1,cmp);
		for(register ll i=1;i<=n;++i)f[i]=i;
		for(register ll i=1;i<=m;++i)
		{
			if(t==n-1)break;
			x=find(a[i].x),y=find(a[i].y);
			if(x==y)continue;
			++t,f[x]=y,s+=a[i].z;
		}
		cout<<s;
		return 0;
	}
	s=t=0;
	sort(a+1,a+m+1,cmp);
	for(register ll i=1;i<=n;++i)f[i]=i;
	for(register ll i=1;i<=m;++i)
	{
		if(t==n-1)break;
		x=find(a[i].x),y=find(a[i].y);
		if(x==y)continue;
		++t,f[x]=y,s+=a[i].z;
	}
	o=s;
	t=((1<<k)-1);
	for(register ll ii=1;ii<=t;++ii)
	{
		p=0;
		for(register ll j=1;j<=k;++j)
			if((ii>>(j-1))&1)p+=c[j][0];
		if(p>=o)continue;
		now=0;
		for(register ll j=1;j<=k;++j)
		{
			if(!((ii>>(j-1))&1))continue;
			for(register ll l=1;l<=n;++l)
				b[++now]={j,l,c[j][l]}; 
		}
		sort(b+1,b+now+1,cmp);
		for(register ll i=1;i<=n;++i)f[i]=i;
		for(register ll i=1;i<=k;++i)nxt[i]=0;
		d=0;
		for(register ll i=1,j=1;i<=m||j<=now;)
		{
			if(d==n-1||p>=o)break;
			if(j>now||(i<=m&&a[i].z<=b[j].z))
			{
				x=find(a[i].x),y=find(a[i].y);
				if(p+a[i].z>=o){p=o;break;}
				else if(x==y){++i;continue;}
				p+=a[i].z,f[x]=y,++d;
				++i;
			}
			else
			{
				if(!nxt[b[j].x])
				{
					nxt[b[j].x]=b[j].y;
					p+=b[j].z;++j;
					continue;
				}
				x=find(nxt[b[j].x]),y=find(b[j].y);
				if(p+b[j].z>=o){p=o;break;}
				else if(x==y){++j;continue;}
				p+=b[j].z,f[x]=y,++d;
				++j;
			}
		}
//		cout<<ii<<' '<<p<<'\n'; 
		o=min(o,p);
	}
	cout<<o;
	return 0;
}
