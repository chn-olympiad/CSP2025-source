#include<bits/stdc++.h>
using namespace std;
//#define int long long <----------------------
int T;
int n;
struct node
{
	long long x;
	int id,col;
}a[300001];
long long b[100001][4];
int cnt[5];
bool vis[100001];
int lst[4];
int c;
long long ans;
void dfs(int x,long long y)
{
	if(x>n) return ans=max(ans,y),void();
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]<n/2)
		{
			cnt[i]++;
			dfs(x+1,y+b[x][i]);
			cnt[i]--;
		}
	}
}
void csh()
{
	c=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	lst[1]=lst[2]=lst[3]=0;
}
bool cmp(node x,node y)
{
	if(x.x!=y.x) return x.x>y.x;
	return x.col<y.col;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n<=10)
		{
			for(int i=1;i<=n;i++) cin>>b[i][1]>>b[i][2]>>b[i][3];
			cnt[1]=cnt[2]=cnt[3]=0;ans=0;
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
		csh();
		for(int i=1;i<=n;i++)
		{
			long long  x,y,z; cin>>x>>y>>z;
			a[++c]={x,i,1};
			a[++c]={y,i,2};
			a[++c]={z,i,3};
			b[i][1]=x,b[i][2]=y,b[i][3]=z;
		}
		sort(a+1,a+1+c,cmp);
		for(int i=1;i<=c;i++)
		{
			long long x=a[i].x;
			int col=a[i].col;
			int id=a[i].id;
			if(vis[id]) continue;
			if(cnt[col]+1>n/2) 
			{
				if(lst[col]) 
				{
					long long ret=ans;
					int zd=0;
					long long Anss=ans;
					for(int j=1;j<=3;j++)
					{
						if(j==col) continue;
						if(cnt[j]+1<=n/2)
						{
							ret=ans-b[lst[col]][col]+b[lst[col]][j]+x;
							if(ret>Anss)
							{
								Anss=ret;
								zd=j;
							}
						}
					}
					if(zd)
					{
						cnt[zd]++;
						lst[zd]=lst[col];
						lst[col]=id;
						ans=Anss;
					}
				}
			}
			else
			{
				ans+=x;
				cnt[col]++;
				vis[id]=1;
				lst[col]=id;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

shen shou bao you

*/
