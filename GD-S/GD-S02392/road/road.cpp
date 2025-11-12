#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define ll long long
#define il inline
using namespace std;

namespace IO {
	void read(int &x)
	{
		x=0;
		int flag=1;
		char ch=getchar();
		while(ch<'0' or ch>'9')
		{
			if(ch=='-')
				flag=-flag;
			ch=getchar();
		}
		while(ch>='0' and ch<='9')
		{
			x=(x<<3)+(x<<1)+ch-'0';
			ch=getchar();
		}
		x*=flag;
	}
} ;
using namespace IO;

const int MAXN=1e4+27;
const int MAXM=1e6+27;

int n,m,K,a[20][MAXN],c[20],fa[MAXN+20];
ll minn=1e18,trm;

struct edge {
	int u,v,w;
} e[MAXM],d[MAXN];

bool cmp(edge x,edge y) {return x.w<y.w;}

int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}

int tote=0,totn,stn;

void solve(ll id)
{
	ll sum=0;
	int tot=0;
	sort(e+1,e+tote+1,cmp);
	for(int i=1;i<=stn;i++)
		fa[i]=i;
	for(int i=1;i<=tote;i++)
	{
		int u,v,w;
		u=e[i].u,v=e[i].v,w=e[i].w;
		int fax=find(u),fay=find(v);
		if(fax==fay)
			continue ;
		fa[fax]=fay;
		sum+=w;
		if(id==-1)
			d[++tot]=e[i];
		if(sum+id>=minn and id>=0)
			return ;
		if(tot==stn-1)
			break;
	}
	if(id==-1)
	{
		minn=sum;
		return ;
	}
	if(sum+id<minn)
	{
		minn=sum+id;
	}
	else
		--stn;
}

int main()
{
	fre("road");
//	scanf("%d %d %d",&n,&m,&K);
	read(n),read(m),read(K);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
//		scanf("%d %d %d",&u,&v,&w);
		read(u),read(v),read(w);
		e[i]={u,v,w};
	}
	stn=n;
	tote=m;
	solve(-1);
	for(int i=1;i<=K;i++)
	{
		read(c[i]);
//		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
//			scanf("%d",&a[i][j]);
			read(a[i][j]);
		}
	}
//	return 0;
	for(int S=1;S<=(1<<K)-1;S++)
	{
		tote=0;
		ll ss=0;
		stn=n;
		for(int j=1;j<n;j++)
			e[++tote]=d[j];
		for(int i=1;i<=K;i++)
		{
			if((S>>(i-1))&1)
			{
				ss+=c[i];
				++stn;
				for(int j=1;j<=n;j++)
					e[++tote]={stn,j,a[i][j]};
			}
		}
//		cout<<ss<<" "<<tote<<" "<<endl;
		solve(ss);
	}
		
	printf("%lld",minn);
	return 0;
}
