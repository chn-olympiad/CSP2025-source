#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353, N=505;
int n, m, ans, a[N], c[N], p[N];
bool vis[N];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(!a[i])return 0;
	}
	return 1;
}
void dfs(int cur)
{
	int cnt=0;
	for(int i=1;i<=cur-1;i++)
	{
		if(a[i]==0)
		{
			cnt++;
		}
		else if(cnt>=c[p[i]])
		{
			cnt++;
		}
	}
//	for(int i=1;i<=cur-1;i++)
//	{
//		cout<<p[i]<<" ";
//	}
//	cout<<cur<<" "<<cnt<<"\n";
	if(cur-1-cnt>=m)
	{
		int tmp=1;
		for(int i=1;i<=n-cur+1;i++)
		{
			tmp*=i;
		}
		ans+=tmp;
		return ;
	}
	if(cur==n+1)return ;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		p[cur]=i;
		vis[i]=1;
		dfs(cur+1);
		vis[i]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]=(int)(c-'0');
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
//	do
//	{
//		int cnt=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]==0)
//			{
//				cnt++;
//			}
//			else if(cnt>=c[p[i]])
//			{
//				cnt++;
//			}
//		}
//		if(n-cnt>=m)
//		{
//			ans++;
//			if(ans>=mod)ans-=mod;
//		}
//	}while(next_permutation(p+1,p+1+n));
	dfs(1);
	cout<<ans;
	return 0;
}

