#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
const int INF = 0x3f3f3f3f;
int T;
int n;
int a[N],b[N],c[N];
pair<int,int> am[N],bm[N],cm[N];
int cnta,cntb,cntc,ans;
bool vis[3][N];
bool cmp(pair<int,int> a1,pair<int,int> a2)
{
	return a1.first>a2.first;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		cnta=n>>1;
		cntb=n>>1;
		cntc=n>>1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&am[i].first,&bm[i].first,&cm[i].first);
			a[i] = am[i] .first;
			b[i] = bm[i] .first;
			c[i] = cm[i] .first;
			am[i].second = i;
			bm[i].second = i;
			cm[i].second = i;
		}
		sort(am+1,am+n+1,cmp);
		sort(bm+1,bm+n+1,cmp);
		sort(cm+1,cm+n+1,cmp);
		for(int i=1;i<=n>>1;i++)
		{
			ans+=am[i].first;
			vis[1][am[i].second] = 1;
		}
		for(int i=1;i<=n>>1;i++)
		{
			if(vis[1][bm[i].second])
			{
				if(a[bm[i].second]<bm[i].first) 
				{
					ans=ans-a[bm[i].second]+bm[i].first;
					vis[1][bm[i].second] = 0;
					vis[2][bm[i].second] = 1;
				}
				else continue;
			}
			else
			{
				vis[2][bm[i].second] = 1;
				ans+=bm[i].first;
			}
		}
		for(int i=1;i<=n>>1;i++)
		{
			if(vis[1][cm[i].second])
			{
				if(a[cm[i].second]<cm[i].first) 
				{
					ans=ans-a[cm[i].second]+cm[i].first;
					vis[1][cm[i].second] = 0;
					vis[3][cm[i].second] = 1;
				}
				else continue;
			}
			else if(vis[2][cm[i].second])
			{
				if(b[cm[i].second]<cm[i].first) 
				{
					ans=ans-b[cm[i].second]+cm[i].first;
					vis[2][cm[i].second] = 0;
					vis[3][cm[i].second] = 1;
				}
				else continue;
			}
			else
			{
				vis[3][cm[i].second] = 1;
				ans+=cm[i].first;
			}
		}
		cout<<ans<<endl;
		ans = 0;
	}
	
}

