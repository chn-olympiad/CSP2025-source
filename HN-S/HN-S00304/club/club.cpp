#include<bits/stdc++.h>
using namespace std;
long long int T,n,a[100005][3],s[5],ans;
void dfs(long long int now,long long int sum)
{
	if(now==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++)
		if(s[i]+1<=n/2)
		{
			s[i]++;
			dfs(now+1,sum+a[now][i]);
			s[i]--;	
		}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		memset(s,0,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

