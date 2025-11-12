#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int asn=0;char ch=getchar();
	while('0'>ch||'9'<ch)ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		asn=(asn<<3)+(asn<<1)+(ch-'0');
		ch=getchar();
	}
	return asn;
}
int n,m,k;
int c[11],a[11][10001],cnt,n1;
struct eg{
	int u,v,w;
}e[1100001];
int fa[10001];
long long ans,ans1;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >q,q1[1031];
int find(int son)
{
	if(fa[son]==son)return son;
	else return fa[son]=find(fa[son]);
}
bool tf[11];
void K()
{
	for(int i=1;i<=cnt;i++)q.push({e[i].w,i});
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<n;i++)
	{
		int r=q.top().second;
		q.pop();
		while(true)
		{
			if(find(e[r].u)==find(e[r].v))
			{
				r=q.top().second;
				q.pop(); 
			}
			else break;
		}
		ans+=(long long)e[r].w;
		fa[find(e[r].u)]=find(e[r].v);
	}
	return ;
}
int T;
void K1()
{
	T++;
	for(int i=1;i<=cnt;i++)q1[T].push({e[i].w,i});
	for(int i=1;i<=n1;i++)fa[i]=i;
	for(int i=1;i<n1;i++)
	{
		int r=q1[T].top().second;
		q1[T].pop();
		while(true)
		{
			if(find(e[r].u)==find(e[r].v))
			{
				r=q1[T].top().second;
				q1[T].pop(); 
			}
			else break;
		}
		ans1+=(long long)e[r].w;
		fa[find(e[r].u)]=find(e[r].v);
	}
	return ;
}
void dg(int now)
{
	if(now==k+1)
	{
		ans1=0;
		cnt=m,n1=n;
		for(int i=1;i<=k;i++)
		{
			if(tf[i])
			{
				n1++;
				ans1+=c[i];
				for(int j=1;j<=n;j++)e[++cnt].u=n1,e[cnt].v=j,e[cnt].w=a[i][j];
			}
		}
		K1();
		ans=min(ans,ans1);
		return ;
	}
	tf[now]=0;
	dg(now+1);
	tf[now]=1;
	dg(now+1);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;i++)e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		c[i]=rd();
		for(int j=1;j<=n;j++)a[i][j]=rd();
	}
	bool B=1;
	for(int i=1;i<=k;i++)
	{
		bool b=0;
		if(c[i]==0)
		{
			for(int j=1;j<=n;j++)
				if(a[i][j]==0)
				{
					b=1;
					for(int _=1;_<=n;_++)
					{
						if(_==j)continue;
						e[++cnt].u=j,e[cnt].v=_,e[cnt].w=a[i][_];
					}
					break;
				}
		}
		if(!b)B=0;
	}
	if(B){K();}
	else
	{
		ans=1000000000000000ll;
		dg(1);
	}
	printf("%lld",ans); 
	return 0;
}
