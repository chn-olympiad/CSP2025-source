#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e3+10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
//1s 512mb polygon
int n;
int a[N],cnt[N],ans;
bool vis[N];//这个下标有没有出现过 
void dfs(int st,int l,int sum,int maxx)
{
	if(l>=3&&sum>2*maxx) 
	{
		ans++;
	}
	for(int i=1;i<st;i++)
	{
		if(vis[i])continue;
		vis[i] = 1;
		dfs(i,l+1,sum+a[i],maxx);
		vis[i] = 0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		dfs(i,1,a[i],a[i]);
	}
	cout<<ans%MOD;
}

