#include<bits/stdc++.h>
using namespace std;
int t,n;
int vis[100005],ar=0,br=0,cr=0,ay[100005],by[100005],cy[100005];
long long ans=0;
struct node{
	int x,idx;
};
node a[100005],b[100005],c[100005];
bool cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>b[i].x>>c[i].x;
			ay[i]=a[i].x;
			by[i]=b[i].x;
			cy[i]=c[i].x;
			a[i].idx=b[i].idx=c[i].idx=i;
		}
		if(n==2)
		{
			ans=max(max(a[1].x+b[2].x,max(c[1].x+a[2].x,a[1].x+c[2].x)),max(b[1].x+a[2].x,max(c[1].x+b[2].x,b[1].x+c[2].x)));
		}
		else
		{
			sort(a+1,a+1+n,cmp);
			sort(b+1,b+1+n,cmp);
			sort(c+1,c+1+n,cmp);
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==1)
					{
						if(vis[a[j].idx]==0&&ar<n/2&&a[j].x==max(max(ay[a[j].idx],by[a[j].idx]),cy[a[j].idx]))
						{
							ans+=a[j].x;
							vis[a[j].idx]=1;
							ar++;
						}
					}
					else if(i==2)
					{
						if(vis[b[j].idx]==0&&br<n/2&&b[j].x==max(max(ay[b[j].idx],by[b[j].idx]),cy[b[j].idx]))
						{
							ans+=b[j].x;
							vis[b[j].idx]=1;
							br++;
						}
					}
					else
					{
						if(vis[c[j].idx]==0&&cr<n/2&&c[j].x==max(max(ay[c[j].idx],by[c[j].idx]),cy[c[j].idx]))
						{
							ans+=c[j].x;
							vis[c[j].idx]=1;
							cr++;
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					if(ar<n/2&&br<n/2&&cr<n/2)
					{
						ans+=max(max(ay[i],by[i]),cy[i]);
						if(max(max(ay[i],by[i]),cy[i])==ay[i]) ar++;
						else if(max(max(ay[i],by[i]),cy[i])==by[i]) br++;
						else cr++;
					}
					else if(ar<n/2&&br<n/2&&cr>=n/2)
					{
						ans+=max(ay[i],by[i]);
						if(max(ay[i],by[i])==ay[i]) ar++;
						else br++;
					}
					else if(ar<n/2&&br>=n/2&&cr<n/2)
					{
						ans+=max(ay[i],cy[i]);
						if(max(ay[i],cy[i])==ay[i]) ar++;
						else cr++;
					}
					else if(ar>=n/2&&br<n/2&&cr<n/2)
					{
						ans+=max(by[i],cy[i]);
						if(max(by[i],cy[i])==by[i]) br++;
						else cr++;
					}
					else if(ar<n/2&&br>=n/2&&cr>=n/2)
					{
						ans+=ay[i];
						ar++;
					}
					else if(ar>=n/2&&br<n/2&&cr>=n/2)
					{
						ans+=by[i];
						br++;
					}
					else if(ar>=n/2&&br>=n/2&&cr<n/2)
					{
						ans+=cy[i];
						cr++;
					}
				}
			}
		}
		cout<<ans<<"\n";
		ar=br=cr=0;
		ans=0;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
