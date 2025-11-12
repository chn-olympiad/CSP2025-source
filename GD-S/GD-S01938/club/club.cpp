#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define ls(rt) (rt<<1)
#define rs(rt) (rt<<1|1)
#define db double

const int N=200;

int n;
int a[100005][4];
int dp1[N/2+5][N/2+5];
int dp2[N/2+5][N/2+5];

bool cmp(int a,int b){return a>b;}

void solve1()
{
	vector<int>v;
	for(int i=1;i<=n;i++)v.push_back(a[i][1]);
	sort(v.begin(),v.end(),cmp);
	int ans=0;
	for(int i = 0;i<n/2;i++)ans+=v[i];
	cout<<ans<<endl;
}

void solve()
{
	cin>>n;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=3;j++)
			cin>>a[i][j];
	if(n>N)
	{
		solve1();
		return;
	}
	memset(dp1,0,sizeof(dp1));
	for(int k = 1;k<=n;k++)
	{
		memset(dp2,0,sizeof(dp2));
		for(int i=0;i<=n/2;i++)
		{
			for(int j = 0;j<=n/2;j++)
			{
				dp2[i][j]=max(dp2[i][j],dp1[i][j]+a[k][3]);
				dp2[i][j+1]=max(dp2[i][j+1],dp1[i][j]+a[k][2]);
				dp2[i+1][j]=max(dp2[i+1][j],dp1[i][j]+a[k][1]);
			}
		}
		for(int i=0;i<=n/2;i++)
			for(int j = 0;j<=n/2;j++)
				dp1[i][j]=dp2[i][j];
	}
	int ans=0;
	for(int i=0;i<=n/2;i++)
		for(int j = 0;j<=n/2;j++)
		{
			int k=n-i-j;
			if(k>n/2)continue;
			ans=max(ans,dp1[i][j]);
		}
	cout<<ans<<endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
