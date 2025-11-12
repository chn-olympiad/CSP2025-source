#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,nop,ani[N][5],po[5*N][5],sum,cnt[5],maxn,maxi;
long long ans;
bool vis[N];
struct node
{
	int x,tpe1,tpe2;
}g[5*N];
bool cmp1(node a,node b)
{
	return a.x>b.x;
}
bool cmp2(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		nop=n/2;sum=0;ans=0;
		memset(cnt,0,sizeof cnt);
		memset(ani,0,sizeof ani);
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			for(int j=1;j<=3;j++)
				cin>>ani[i][j];
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				g[++sum].x=ani[i][j];
				g[sum].tpe1=i;
				g[sum].tpe2=j;
			}
		sort(g+1,g+3*n+1,cmp1);
		for(int i=1;i<=3*n;i++)
			if(vis[g[i].tpe1])
			{
				ans+=g[i].x;
				cnt[g[i].tpe2]++;
				vis[g[i].tpe1]=0;
			}
		sort(g+1,g+3*n+1,cmp2);
		for(int i=1;i<=3*n;i++)
			if(cnt[g[i].tpe2]>nop&&!vis[g[i].tpe1])
			{
				maxn=0;maxi=0;
				for(int j=1;j<=3;j++)
					if(j!=g[i].tpe2&&ani[g[i].tpe1][j]>maxn&&cnt[j]<nop)
					{
						maxn=ani[g[i].tpe1][j];
						maxi=j;
					}
				ans+=maxn;
				ans-=g[i].x;
				cnt[g[i].tpe2]--;
				cnt[maxi]++;
				vis[g[i].tpe1]=1;
			}
		cout<<ans<<'\n';
	}
	return 0;
}