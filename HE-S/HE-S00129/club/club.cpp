#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int maxn=2e5+10;
int a[maxn][4];
int cnt[4];
int T,n;
int pa[maxn],pb[maxn],pc[maxn];
int sum=0;
struct node{
	int maxx;
	int maxzb;
	int midd;
	int midzb;
	int minn;
	int minzb;
	int dbz;
}ys[maxn];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(register int o=1;o<=T;o++)
	{
		sum=0;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		memset(ys,0,sizeof(ys));
		cin>>n;
		for(register int i=1;i<=n;i++)
		{
			int maxx=-1;
			int minn=INT_MAX;
			int maxzb=0;
			int minzb=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>maxx)
				{
					maxx=a[i][j];
					maxzb=j;
				}
				if(a[i][j]<=minn)
				{
					minn=a[i][j];
					minzb=j;
				}
			}
			ys[i].maxx=maxx;
			ys[i].maxzb=maxzb;
			ys[i].minn=minn;
			ys[i].minzb=minzb;
			ys[i].midzb=6-maxzb-minzb;
			ys[i].midd=a[i][ys[i].midzb];
			ys[i].dbz=ys[i].maxx-ys[i].midd;
		}
		int cnta=0,cntb=0,cntc=0;
		for(register int i=1;i<=n;i++)
		{
			int zb=ys[i].maxzb;
			int num=ys[i].dbz;
			if(zb==1)
			{
				pa[++cnta]=num;
			}
			else if(zb==2)
			{
				pb[++cntb]=num;
			}
			else if(zb==3)
			{
				pc[++cntc]=num;
			}
			sum+=ys[i].maxx;
		}
		if(cnta>n/2)
		{	
			sort(pa+1,pa+1+cnta);
			for(int u=1;u<=cnta-n/2;u++)
			{
				sum-=pa[u];
			}			
		}
		else if(cntb>n/2)
		{
			sort(pb+1,pb+1+cntb);
			for(int u=1;u<=cntb-n/2;u++)
			{
				sum-=pb[u];	
			}				
		}
	 	else if(cntc>n/2)
	 	{
	 		sort(pc+1,pc+1+cntc);
			for(int u=1;u<=cntc-n/2;u++)
			{
				sum-=pc[u];	
			}	 		
		}	
		cout<<sum<<"\n";		 		
	}
	return 0;
}
