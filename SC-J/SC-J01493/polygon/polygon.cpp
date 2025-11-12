#include <bits/stdc++.h>
#define int long long
const int q=998244353;
using namespace std;
int a[5010];
int vis[5010];
int n;
set<string> s;
void dfs(int step,int sum,int mx)
{
	if(step==2)
	{
		return ;
	}
	if(sum>mx*2)
	{
		string t="";
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				int k=i;
				while(k)
				{
					t+=" ";
					t[cnt]=k%10+'0';
					cnt++;	
					k/=10;
				}
			}
		}
		s.insert(t);
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				continue;
			}
			vis[i]=1;
			if(a[i]==mx)
			{
				int x=lower_bound(a+1,a+1+n,a[i])-a;
				mx=a[x-1];			
			}				
			dfs(step-1,sum-a[i],mx);
			vis[i]=0;
		}
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			if(vis[i]!=1)
			{
				vis[i]=1;
				if(a[i]==mx)
				{
					int x=lower_bound(a+1,a+1+n,a[i])-a;
					mx=a[x-1];			
				}				
				dfs(step-1,sum-a[i],mx);
				vis[i]=0;
				break;
			}
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	int mx=-1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1)
	{
		int x=1,y=2,ans=0;
		for(int i=1;i<=n;i++)
		{
			x*=i;
		}
		for(int i=3;i<=n;i++)
		{
			y*=i;
			int z=x/y;
			ans=(ans+z)%q;
		}
		printf("%lld",ans%q);
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(n,sum,mx);
	printf("%lld",s.size()%q);
	return 0;
}
