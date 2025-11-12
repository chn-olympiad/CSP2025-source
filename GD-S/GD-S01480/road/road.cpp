#include<bits/stdc++.h>
using namespace std;
int id;
int fa[100005];
int n,m,k;
struct edge
{
	int to,fro,co,ki;
}a[1500005];
void add(int x,int y,int w,int op)
{
	id++;
	a[id].to=y;
	a[id].fro=x;
	a[id].co=w;
	a[id].ki=op;
}
int c[105];
int rc[105];
int cnt=0;
inline int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
	{
		return;
	}
	if(x>y)
	{
		swap(x,y);
	}
	fa[y]=x;
}
inline bool cmp(edge x,edge y)
{
	return x.co<y.co;
}
long long ans=1e18;
int i,j;
inline long long kru(int x)
{
	long long ansn=0;
	bool ok[105];
	ok[0]=1;
	int nc=cnt-1;
	ansn=0;
	while(nc>-1)
	{
		ok[rc[nc+1]]=0;
		if(x>=(1<<nc))
		{
			x-=(1<<nc);
			ok[rc[nc+1]]=1;
			ansn+=c[rc[nc+1]];
			//cout<<rc[nc+1];
		}
		nc--;
	}
	if(ansn>ans)
	{
		return ansn;
	}
	//cout<<endl;
	for(i=1;i<=n+10;i++)
	{
		fa[i]=i;
	}
	for(i=1;i<=id;i++)
	{
		if(ok[a[i].ki])
		{
			if(find(a[i].fro)!=find(a[i].to))
			{
				merge(a[i].fro,a[i].to);
				ansn+=a[i].co;
				if(ansn>ans)
				{
					return ansn;
				}
				//cout<<a[i].fro<<" "<<a[i].to<<" "<<a[i].co<<" "<<a[i].ki<<" "<<ok[a[i].ki]<<endl;
			}
		}
	}
	//cout<<endl;
	return ansn;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w,0);
		//add(y,x,w,0);
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		int wtf=i;
		if(c[i]==0)
		{
			wtf=0;
		}
		else
		{
			rc[++cnt]=i;
		}
		for(j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			add(i+n,j,w,wtf);
			//add(j,i+n,w,wtf);
		}
	}
	sort(a+1,a+id+1,cmp);
	ans=kru(0);
	for(i=1;i<(1<<cnt);i++)
	{
		ans=min(kru(i),ans);
	}
	cout<<ans<<endl;
	return 0;
}
