#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+105,M=2e6+5;
struct E{
	int x,y,w;
}e[M];
bool operator<(E a,E b){return a.w==b.w?(a.x==b.x?a.y>b.y:a.x>b.x):a.w<b.w;} 
int n,m,k,fa[N],c[20],a[20][N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
multiset<E>S;
ll res=1e18;
inline int read()
{
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	n=read(),m=read(),k=read();
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read(),w=read();
			e[i]={x,y,w};
		}
		sort(e+1,e+m+1);
		for(int i=1;i<=n;i++)fa[i]=i;
		int cnt=0;ll ans=0;
		for(int i=1;i<=m;i++)
		{
			int x=find(e[i].x),y=find(e[i].y);
			if(x==y)continue;
			fa[x]=y;
			ans+=e[i].w;
			cnt++;
			if(cnt==n-1)break;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),w=read();
		S.insert({x,y,w});
	}
	for(int i=0;i<k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
	for(int s=0;s<(1<<k);s++)
	{
		int delta=s-1,K=__builtin_popcount(s);
		if(s)
		{
			delta^=s;
			for(int i=0;i<k;i++)
				if(delta>>i&1)
					if(s>>i&1)
						for(int j=1;j<=n;j++)
							S.insert({i+1+n,j,a[i][j]});		
				else for(int j=1;j<=n;j++)
						S.erase(S.find({i+1+n,j,a[i][j]}));
		}
		ll ans=0;
		for(int i=0;i<k;i++)
			if(s>>i&1)ans+=c[i];
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int cnt=0;
		for(auto t:S)
		{
			int x=t.x,y=t.y,w=t.w;
			x=find(x),y=find(y);
			if(x==y)continue;
			fa[x]=y;
			ans+=w;
			cnt++;
			if(cnt==n+K-1)break;
		}
		res=min(res,ans);
	}
	printf("%lld",res);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
