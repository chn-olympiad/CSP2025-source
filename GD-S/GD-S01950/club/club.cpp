#include<bits/stdc++.h>
using namespace std;
int t,n,cnt_bm[4];
bool vis[100500];
struct nice{
	int ren,bm,data;
}like[300500];
bool cmp(nice n1,nice n2)
{
	if(n1.data==n2.data)
	{
		return n1.ren<n2.ren;
	} 
	return n1.data>n2.data;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int w=1;w<=t;w++)
	{
		scanf("%d",&n);
		int cnt=0;
		long long ans=0;
		memset(vis,0,sizeof(vis));
		memset(cnt_bm,0,sizeof(cnt_bm));
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			like[++cnt]={i,1,a};
			like[++cnt]={i,2,b};
			like[++cnt]={i,3,c};
		}
		sort(like+1,like+1+cnt,cmp);
		for(int i=1;i<=cnt;i++)
		{
			if(vis[like[i].ren]==0 && cnt_bm[like[i].bm]<n/2)
			{
				ans+=like[i].data;
				cnt_bm[like[i].bm]++;
				vis[like[i].ren]=1;
				cout<<like[i].ren<<" "<<like[i].bm<<" "<<like[i].data<<endl;
			}
		} 
		printf("%lld\n",ans); 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

