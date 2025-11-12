#include<bits/stdc++.h>

using namespace std;

int n;
int v[100010][3];
int cnt[3] = {0,0,0};
int ans=0;
int sum=0;
//int cnt[3];
//int dp[100][100][100][100];

void dfs(int a)
{
	if(a == n+1)
	{
//		cout<<"sum "<<sum<<endl;
		ans = max(ans,sum);
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(cnt[i]<n/2)
		{
			cnt[i]++;
			sum += v[a][i];
			dfs(a+1);
			sum -= v[a][i];
			cnt[i]--;
		}
	}
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans = 0;
		sum = 0;
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>v[i][0]>>v[i][1]>>v[i][2];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
