#include<bits/stdc++.h> 
using namespace std;
long long n,a[5001],mod=998244353,vis[21],d[21],ans=0,sum[5001][3],z[5001][2];
vector<long long> g;
bool p ()
{
	long long maxx=0,cnt=0,x=0;
	for (int i=1;i<=n;i++) 
	{
		if (!vis[i]) continue;
		cnt++;
		maxx=max(maxx,a[i]);
	}
	if (cnt<3) return 0;
	for (int i=1;i<=n;i++) 
	{
		if (!vis[i]) continue;
		x+=a[i];
	}
	if (x>2*maxx) return 1;
	return 0;
}
void dfs(int s)
{
	if (s==n+1) 
	{
		if (p()) 
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	vis[s]=1;
	dfs(s+1);
	vis[s]=0;
	dfs(s+1);
}
void zxy ()
{
	dfs(1);
	cout<<ans;
	exit(0);
}
int main ()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (n<=20) zxy();
	for (int i=1;i<=n;i++)
	{
		int len=g.size();
		for (int j=0;j<len;j++) z[j][0]=sum[g[j]][0],z[j][1]=sum[g[j]][1];
		for (int j=0;j<len;j++)
		{
			if (g[j]+a[i]>a[n]) continue;
			if (sum[g[j]+a[i]][0]==0&&sum[g[j]+a[i]][1]==0) g.push_back(g[j]+a[i]);
			sum[g[j]+a[i]][1]=(sum[g[j]+a[i]][1]+z[j][0])%mod;
			sum[g[j]+a[i]][1]=(sum[g[j]+a[i]][1]+z[j][1])%mod;
		}
		if (sum[a[i]][0]==0&&sum[a[i]][1]==0)  g.push_back(a[i]);
		sum[a[i]][0]++;
	}
	int l=n;
	for (int i=a[n];i>=1;i--)
	{
		while (a[l]>=i) l--;
		sum[i][2]=n-l;
	}
	ans=1;
	for (int i=1;i<=n;i++) 
	{
		ans=ans*2;
		ans%=mod;
	}
	ans=(ans-1-n-n*(n-1)/2+mod)%mod;
	for (int i=1;i<=a[n];i++) ans=(ans-sum[i][1]*sum[i][2]+mod*(n+2))%mod;
	cout<<ans<<endl;
	return 0;
}
