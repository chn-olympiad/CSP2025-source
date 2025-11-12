#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int a[maxn][5],cnt[5],n,vis[maxn][5];
struct node{
	int id,w,c;//person max-i
	bool operator <(const node &x) const{
		return w>x.w;
	}
};
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int sum=0;
		priority_queue<node> q[5];
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		{
			int maxx=-1,maxc;
			for(int j=1;j<=3;j++) 
				if(a[i][j]>maxx) maxx=a[i][j],maxc=j;
			for(int j=1;j<=3;j++)
				if(j!=maxc)
					q[maxc].push((node){i,a[i][maxc]-a[i][j],j});
			cnt[maxc]++,sum+=maxx;
			if(cnt[maxc]+cnt[maxc]>n)
			{
				cnt[maxc]--;
				int s1=q[maxc].top().w,c1=q[maxc].top().c,k=q[maxc].top().id,c2;
				while(vis[k][maxc]) 
				{
					q[maxc].pop();
					for(int j=1;j<=3;j++)
						if(j!=maxc && j!=c1) c2=j;
					if(!vis[k][c1])q[c1].push((node){i,a[i][c1]-a[i][c2],c2});
					s1=q[maxc].top().w,c1=q[maxc].top().c,k=q[maxc].top().id;
				}
				sum-=s1,cnt[c1]++;
				q[maxc].pop(),vis[k][maxc]=1;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
