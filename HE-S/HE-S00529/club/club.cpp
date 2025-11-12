#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int a[N][5];
int cnt[N];
int n,t;
int ans,hn;
void dfs(int k,int sum)
{
	if(k>n)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]>=hn)
		{
			continue;
		}
		cnt[i]++;
		dfs(k+1,sum+a[k][i]);
		cnt[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		hn=n/2;
		ans=-1;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
