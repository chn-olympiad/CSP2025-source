#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,n,k,cnt[N][3],ans;
void dfs(int last,int m,int yi,int er,int san)
{
	if(m-1==n)
	{
		if(yi<=k&&er<=k&&san<=k)
		{
			ans=max(ans,last);
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			dfs(last+cnt[m][i],m+1,yi+1,er,san);
		}
		if(i==2)
		{
			dfs(last+cnt[m][i],m+1,yi,er+1,san);
		}
		if(i==3)
		{
			dfs(last+cnt[m][i],m+1,yi,er,san+1);
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		k=n/2;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>cnt[i][1]>>cnt[i][2]>>cnt[i][3];
		}
		dfs(0,1,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
