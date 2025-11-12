#include<bits/stdc++.h>
using namespace std;
int t,ans,a[100005][3];
void dfs(int setp,int cnt0,int cnt1,int cnt2,int n,int cnt)
{
	if(cnt0>n/2||cnt1>n/2||cnt2>n/2)
	{
		return; 
	}
	if(setp>n)
	{
		ans=max(ans,cnt);
		return;
	}	
	dfs(setp+1,cnt0+1,cnt1,cnt2,n,cnt+a[setp][0]);
	dfs(setp+1,cnt0,cnt1+1,cnt2,n,cnt+a[setp][1]);
	dfs(setp+1,cnt0,cnt1,cnt2+1,n,cnt+a[setp][2]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		} 
		dfs(1,0,0,0,n,0);
		cout<<ans<<endl;
	}
	return 0;
}
