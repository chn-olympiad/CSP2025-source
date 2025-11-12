#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,tot[3],ans;
vector<int>b[3];
struct mem{int a[3],mf,ms;}a[N];
bool cmp(int ca,int cb){return a[ca].a[a[ca].mf]-a[ca].a[a[ca].ms]<a[cb].a[a[cb].mf]-a[cb].a[a[cb].ms];}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		b[0].clear();b[1].clear();b[2].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a[0],&a[i].a[1],&a[i].a[2]);
			if(a[i].a[0]>=a[i].a[1]&&a[i].a[0]>=a[i].a[2])
			{
				a[i].mf=0;
				if(a[i].a[1]>=a[i].a[2]) a[i].ms=1;
				else a[i].ms=2;
			}
			if(a[i].a[1]>=a[i].a[0]&&a[i].a[1]>=a[i].a[2])
			{
				a[i].mf=1;
				if(a[i].a[0]>=a[i].a[2]) a[i].ms=0;
				else a[i].ms=2;
			}
			if(a[i].a[2]>=a[i].a[0]&&a[i].a[2]>=a[i].a[1])
			{
				a[i].mf=2;
				if(a[i].a[0]>=a[i].a[1]) a[i].ms=0;
				else a[i].ms=1;
			}
			b[a[i].mf].push_back(i);
			ans+=a[i].a[a[i].mf];
		}
		if((int)b[0].size()<=n/2&&(int)b[1].size()<=n/2&&(int)b[2].size()<=n/2)
		{
			printf("%d\n",ans);
			continue;
		}
		if((int)b[0].size()>n/2)
		{
			sort(b[0].begin(),b[0].end(),cmp);
			for(int i=0;i<(int)b[0].size()-n/2;i++) ans+=a[b[0][i]].a[a[b[0][i]].ms]-a[b[0][i]].a[a[b[0][i]].mf];
		}
		if((int)b[1].size()>n/2)
		{
			sort(b[1].begin(),b[1].end(),cmp);
			for(int i=0;i<(int)b[1].size()-n/2;i++) ans+=a[b[1][i]].a[a[b[1][i]].ms]-a[b[1][i]].a[a[b[1][i]].mf];
		}
//		cout<<b[0].size()<<' '<<b[1].size()<<' '<<b[2].size()<<endl;
		if((int)b[2].size()>n/2)
		{
			sort(b[2].begin(),b[2].end(),cmp);
			for(int i=0;i<(int)b[2].size()-n/2;i++) ans+=a[b[2][i]].a[a[b[2][i]].ms]-a[b[2][i]].a[a[b[2][i]].mf];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/
