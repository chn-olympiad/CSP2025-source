#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,ans=0;
int a[N][5];
bool flag[N];
void dfs(int cnt1,int cnt2,int cnt3,int sum,int all,int last)
{
	if(all==n&&cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=last;i<=n;i++)
	{
		if(flag[i]) continue;
		flag[i]=1;
		dfs(cnt1+1,cnt2,cnt3,sum+a[i][1],all+1,i+1);
		dfs(cnt1,cnt2+1,cnt3,sum+a[i][2],all+1,i+1);
		dfs(cnt1,cnt2,cnt3+1,sum+a[i][3],all+1,i+1);
		flag[i]=0;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++) flag[i]=0;
		dfs(0,0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}