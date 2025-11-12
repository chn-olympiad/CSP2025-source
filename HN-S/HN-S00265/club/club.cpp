#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int N=2e5+114;
int n,a[N][3],dp[N][4][2][2][2];//到第i个人，选1/2/3社团之后，社团不满n/2(0)/满了n/2(1)
int ans=0;
void dfs(int u,int sh1,int sh2,int sh3,int sum)
{
	if(u==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(sh1<n/2)dfs(u+1,sh1+1,sh2,sh3,sum+a[u][1]);
	if(sh2<n/2)dfs(u+1,sh1,sh2+1,sh3,sum+a[u][2]);
	if(sh3<n/2)dfs(u+1,sh1,sh2,sh3+1,sum+a[u][3]);
}
int b[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;ans=0;
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 || a[i][3]!=0)flag=1;
		}
		if(!flag)
		{
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(int i=n/2+1;i<=n;i++)ans+=b[i];
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
希望这次顺利。（14：29）

524288

完了，贪心错了，DP想不出来转移，第一题好南

16:49 只有20分。
#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int N=2e5+114;
int n,a[N][3],dp[N][4][2][2][2];//到第i个人，选1/2/3社团之后，社团不满n/2(0)/满了n/2(1)
int ans=0;int cnt=0;
void dfs(int u,int sh1,int sh2,int sh3,int sum)
{
	cnt++;
	if(u==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(sh1<n/2)dfs(u+1,sh1+1,sh2,sh3,sum+a[u][1]);
	if(sh2<n/2)dfs(u+1,sh1,sh2+1,sh3,sum+a[u][2]);
	if(sh3<n/2)dfs(u+1,sh1,sh2,sh3+1,sum+a[u][3]);
}
signed main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;ans=0;cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
*/