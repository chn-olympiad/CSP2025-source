#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
const int N=1e5+5;
int T,n,cnt[4],ans=0;
struct node {int x[4],id1,id2,id3;} a[N];
struct node1
{
	int dlt,id;
	inline bool operator<(const node1& rhs) const {return dlt<rhs.dlt||(dlt==rhs.dlt&&id<rhs.id);}
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		set<node1> d[4];
		n=read();
		for(int i=1;i<=n;++i)
		{
			a[i].x[1]=read();
			a[i].x[2]=read();
			a[i].x[3]=read();
			int x[4];
			x[1]=a[i].x[1];
			x[2]=a[i].x[2];
			x[3]=a[i].x[3];
			sort(x+1,x+4);
			for(int j=1;j<=3;++j)
			{
				if(a[i].x[j]==x[3])
					a[i].id1=j;
				if(a[i].x[j]==x[2])
					a[i].id2=j;
				if(a[i].x[j]==x[1])
					a[i].id3=j;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(cnt[a[i].id1]<n/2)
			{
				ans+=a[i].x[a[i].id1];
				++cnt[a[i].id1];
				d[a[i].id1].insert({a[i].x[a[i].id1]-a[i].x[a[i].id2],i});
			}
			else
			{
				int dlt=a[i].x[a[i].id1]-a[i].x[a[i].id2];
				node1 beg=*d[a[i].id1].begin();
				if(dlt>beg.dlt)
				{
					ans+=a[i].x[a[i].id1]-beg.dlt;
					d[a[beg.id].id2].insert({a[beg.id].x[a[beg.id].id2]-a[beg.id].x[a[beg.id].id3],beg.id});
					++cnt[a[beg.id].id2];
					d[a[i].id1].erase(d[a[i].id1].begin());
					d[a[i].id1].insert({a[i].x[a[i].id1]-a[i].x[a[i].id2],i});
				}
				else
				{
					ans+=a[i].x[a[i].id2];
					++cnt[a[i].id2];
					d[a[i].id2].insert({a[i].x[a[i].id2]-a[i].x[a[i].id3],i});
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
