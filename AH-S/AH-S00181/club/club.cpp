#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MAXN=1e5+2;
int t;
LL ans;
int n,a[MAXN],b[MAXN],c[MAXN];
bool fa,fb;
LL mp[305][305][305];
bool cmp(int xx,int yy)
{
	return xx>yy;
}
void dfs(int t,int s1,int s2,int s3,LL cnt)
{
	if(t>n)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(mp[s1][s2][s3]>cnt) return ;
	mp[s1][s2][s3]=cnt;
	if(s1<n/2) dfs(t+1,s1+1,s2,s3,cnt+a[t]);
	if(s2<n/2) dfs(t+1,s1,s2+1,s3,cnt+b[t]);
	if(s3<n/2) dfs(t+1,s1,s2,s3+1,cnt+c[t]);
	else 
	{
		ans=max(ans,cnt);
		return ;
	}
	return ;
}
void dfs2(int t,int s1,int s2,LL cnt)
{
	if(t>n)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(mp[s1][s2][0]>cnt) return ;
	mp[s1][s2][0]=cnt;
	if(s1<n/2) dfs2(t+1,s1+1,s2,cnt+a[t]);
	if(s2<n/2) dfs2(t+1,s1,s2+1,cnt+b[t]);
	else 
	{
		ans=max(ans,cnt);
		return ;
	}
	return ;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		fa=1,fb=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]) fb=fa=0;
			if(b[i]) fa=0;
		}
		if(!fa&&!fb)
		{
			memset(mp,0,sizeof mp);
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
		else
		{
			if(fa)
			{
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++) ans+=a[i];
				cout<<ans<<"\n";
			}
			else if(fb)
			{
				memset(mp,0,sizeof mp);
				dfs2(1,0,0,0);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
