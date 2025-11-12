#include<cstdio>
#include<algorithm>
using namespace std;

#define N 100005

namespace code
{
	int n;
	struct node
	{
		int x,y,z;
		int maxs,last;
		int maxt,lastt;
		friend bool operator<(const node &a,const node &b){return a.last-a.maxs>b.last-b.maxs;}
	} a[N];
	int qs[5][N],head[5],tail[5];
	
	signed main()
	{
		int tt;
		scanf("%d",&tt);
		while(tt--)
		{
			head[1]=head[2]=head[3]=1;
			tail[1]=tail[2]=tail[3]=0;
			scanf("%d",&n);
			for(int i=1;i<=n;++i)
			{
				scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
				a[i].maxs=a[i].x;
				a[i].maxt=1;
				if(a[i].maxs<a[i].y)
					a[i].last=a[i].x,
					a[i].lastt=1,
					a[i].maxs=a[i].y,
					a[i].maxt=2;
				else a[i].last=a[i].y,
					a[i].lastt=2;
				if(a[i].maxs<a[i].z)
					a[i].last=a[i].maxs,
					a[i].lastt=a[i].maxt,
					a[i].maxs=a[i].z,
					a[i].maxt=3;
				else if(a[i].last<a[i].z)
					a[i].last=a[i].z,
					a[i].lastt=3;
			}
			// if(tt==2)
			// 	for(int i=1;i<=n;++i)
			// 		fprintf(stderr,"a[%d] (maxs,maxt)=(%d,%d) (last,lastt)=(%d,%d)\n",i,a[i].maxs,a[i].maxt,a[i].last,a[i].lastt);
			// if(tt==2)
			// 	for(int i=1;i<=n;++i)
			// 		fprintf(stderr,"a[%d] %d %d %d\n",i,a[i].x,a[i].y,a[i].z);
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=1;i<=n;++i)
			{
				int *maxq=qs[a[i].maxt],*lastq=qs[a[i].lastt];
				int &maxhead=head[a[i].maxt],&maxtail=tail[a[i].maxt];
				int &lasttail=tail[a[i].lastt];
				if(maxhead>maxtail||maxtail-maxhead+1<n>>1)
					ans+=a[i].maxs,
					maxq[++maxtail]=i;
				else if(a[maxq[maxhead]].last-a[maxq[maxhead]].maxs+a[i].maxs>a[i].last)
					ans+=a[maxq[maxhead]].last-a[maxq[maxhead]].maxs+a[i].maxs,
					qs[a[maxq[maxhead]].lastt][++head[a[maxq[maxhead]].lastt]]=maxq[maxhead],
					++maxhead,
					maxq[++maxtail]=i;
				else
					ans+=a[i].last,
					lastq[++lasttail]=i;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}

signed main()
{
	// freopen("err.txt","w",stderr);
	// freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	code::main();
	return 0;
}