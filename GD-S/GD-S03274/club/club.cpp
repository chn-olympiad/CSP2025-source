#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
#define int long long
const int N=2e5+5;
int a[N][10],cnt[30],vis[N],st[N],top;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,maxx=-1,id=0,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=sum=0,top=0;
		for(int i=1;i<=n;i++)
		{
			maxx=-1,id=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(maxx<a[i][j])
					maxx=a[i][j],id=j;
			}
			sum+=maxx;
			cnt[id]++;
			vis[i]=id;
		}
		if(cnt[1]*2<=n&&cnt[2]*2<=n&&cnt[3]*2<=n)
		{
			cout<<sum<<"\n";
			continue;
		}
		if(cnt[1]*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==1)
					st[++top]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}
			sort(st+1,st+top+1);
			for(int i=1;i<=cnt[1]-n/2;i++)
				sum-=st[i];
		}
		else if(cnt[2]*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==2)
					st[++top]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}
			sort(st+1,st+top+1);
			for(int i=1;i<=cnt[2]-n/2;i++)
				sum-=st[i];
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==3)
					st[++top]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
			}
			sort(st+1,st+top+1);
			for(int i=1;i<=cnt[3]-n/2;i++)
				sum-=st[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
