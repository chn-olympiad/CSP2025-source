#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100005][5];
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum)
{
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
	if(x==n+1)
	{
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) ans=max(ans,sum);
		return;
	}
	dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x][1]);
	dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x][2]);
	dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]!=0&&a[i][2]==0&&a[i][3]==0) continue;
			flag=1;
		}
		ans=0;
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else if(flag==0)
		{
			int num[100005];
			for(int i=1;i<=n;i++) num[i]=a[i][1];
			sort(num+1,num+n+1);
			for(int i=n;i>=n-n/2+1;i--) ans+=num[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
