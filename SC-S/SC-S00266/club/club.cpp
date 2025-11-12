#include<bits/stdc++.h>
#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

const int maxn=1e5+5;
int t,n;
struct node
{
	int id;
	int a1,a2,a3;
	bool operator< (node t)
	{
		if(a1!=t.a1) return a1<t.a1;
		else if(a2!=t.a2) return a2<t.a2;
		else return a3<t.a3;
	}
};
node a[maxn];
int ans,ret,cnt[4];

void dfs(int x,int res)
{
	if(x>n)
	{
		ret=max(ret,res);
		return ;
	}
	if(res<=ret) return ;
	if(cnt[1]<n/2)
	{
		cnt[1]++;
		dfs(x+1,res+a[x].a1);
		cnt[1]--;
	}
	if(cnt[2]<n/2)
	{
		cnt[2]++;
		dfs(x+1,res+a[x].a2);
		cnt[2]--;
	}
	if(cnt[3]<n/2)
	{
		cnt[3]++;
		dfs(x+1,res+a[x].a3);
		cnt[3]--;
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	fore(l,1,t)
	{
		memset(cnt,0,sizeof(cnt));
		ans=0;
		cin>>n;
		fore(i,1,n)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int x=max({a[i].a1,a[i].a2,a[i].a3});
			a[i].a1-=x;a[i].a2-=x;a[i].a3-=x;
			ans+=x;
		}
//		fore(i,1,n) cout<<a[i].a1<<a[i].a2<<a[i].a3<<'\n';
		if(n<=10)
		{
			ret=-1e5;
			dfs(1,0);
			cout<<ans+ret<<'\n';
		}
		else
		{
			sort(a+1,a+n+1);
			fore(i,1,n)
			{
				int x=max({a[i].a1,a[i].a2,a[i].a3});
				if(a[i].a1==x)
				{
					if(cnt[1]<n/2)
					{
						ans+=a[i].a1;
						cnt[1]++;
					}
					else
					{
						if(a[i].a2>a[i].a3)
						{
							ans+=a[i].a2;
							cnt[2]++;
						}
						else
						{
							ans+=a[i].a3;
							cnt[3]++;
						}
					}
				}
				else if(a[i].a2==x)
				{
					if(cnt[2]<n/2)
					{
						ans+=a[i].a2;
						cnt[2]++;
					}
					else
					{
						if(a[i].a1>a[i].a3)
						{
							ans+=a[i].a1;
							cnt[1]++;
						}
						else
						{
							ans+=a[i].a3;
							cnt[3]++;
						}
					}
				}
				else
				{
					if(cnt[3]<n/2)
					{
						ans+=a[i].a3;
						cnt[3]++;
					}
					else
					{
						if(a[i].a1>a[i].a2)
						{
							ans+=a[i].a1;
							cnt[1]++;
						}
						else
						{
							ans+=a[i].a2;
							cnt[2]++;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
