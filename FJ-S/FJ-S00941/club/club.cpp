#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn][4];
int mi[maxn];
int p[maxn];
int cnt[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(p,0,sizeof(p));
		int n;
		cin>>n;
		int ans=0;
		for(int i=0;i<=n;i++)
		{
			mi[i]=INT_MAX;
		}
		for(int i=1;i<=n;i++)
		{
			int pd=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(!pd || a[i][j]>a[i][pd])
				{
					pd=j;
				}
			}
			cnt[pd]++;
			ans+=a[i][pd];
			p[i]=pd;
		}
		int d=-1;
		if(cnt[1]>n/2) d=1;
		if(cnt[2]>n/2) d=2;
		if(cnt[3]>n/2) d=3;
		 for(int i=1;i<=n;i++)
		 {
		 	if(p[i]==d)
		 	{
		 		int minn=INT_MAX;
		 		for(int j=1;j<=3;j++)
		 		{
		 			if(j!=d)
		 			{
		 				minn=min(minn,a[i][d]-a[i][j]);
					 }
				 }
				 mi[i]=minn;
			 }
		 }
		 sort(mi+1,mi+n+1);
		 for(int i=1;i<=cnt[d]-n/2;i++)
		 {
		 	ans-=mi[i];
		 }
		 cout<<ans<<'\n';
		 
		
	}
	return 0;
 }
