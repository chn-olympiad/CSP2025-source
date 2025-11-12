#include<bits/stdc++.h>
using namespace std;
int a[500005],dp[5000][5000],m,ans;
bool vis[500005];

struct no{
	int len,l,r;
} b[10000];

bool cmp(no x,no y)
{
	if(x.len==y.len) return x.l<y.l;
	return x.len<y.len;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i]=1;
	}
	for(int i=1;i<=n;i++) dp[1][i]=dp[1][i-1]^a[i];
	for(int i=2;i<=n;i++)
	{
		dp[i][i]=a[i];
		for(int j=i+1;j<=n;j++) dp[i][j]=dp[i-1][i-1]^dp[i-1][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j]==k)
			{
				b[++m].len=j-i+1;
				b[m].l=i;
				b[m].r=j;
			}
		}
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		bool f=1;
		for(int j=b[i].l;j<=b[i].r;j++)
		{
			if(!vis[j])
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			for(int j=b[i].l;j<=b[i].r;j++) vis[j]=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
