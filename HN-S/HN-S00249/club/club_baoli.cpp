#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
	Author: wbw_121124
	ÈË½ÜµØÁé 
	club_baoli.cpp
*/
const int N = 1e5 + 5;
int t,n,a[N][3],ans;
void dfs(int x,int cnt0,int cnt1,int cnt2,int sum)
{
	if(cnt0>n/2)
		return;
	if(cnt1>n/2)
		return;
	if(cnt2>n/2)
		return;
	if(x==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,cnt0+1,cnt1,cnt2,sum+a[x][0]);
	dfs(x+1,cnt0,cnt1+1,cnt2,sum+a[x][1]);
	dfs(x+1,cnt0,cnt1,cnt2+1,sum+a[x][2]);
	return;
}
signed main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
