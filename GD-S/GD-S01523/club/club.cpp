#include <bits/stdc++.h>
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 1e5+5,M = 205;
int n;
int a[N][5];
int dp[M][M][M];
int A[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while (T--)
	{
		n=read();
		for (int i = 1; i <= n; i++) a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		if (n<=200)
		{
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					for (int k = 0; k <= n; k++)
						dp[i][j][k]=0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					if (j>n/2) break;
					for (int k = 0; k <= i; k++)
					{
						if (k>n/2||j+k>i) break;
						int l = i-j-k;
						if (l>n/2) continue;
						if (j>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
						if (k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
						if (l>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					}
				}
			}
			int ans = 0;
			for (int i = 0; i <= n/2; i++)
			{
				for (int j = 0; j <= n/2; j++)
				{
					int k = n-i-j;
					if (k>n/2) continue;
					ans=max(ans,dp[n][i][j]);
				}
			}
			writech(ans,'\n');
			continue;
		}
		bool flagA = true;
		for (int i = 1; i <= n; i++)
		{
			if (a[i][2]!=0||a[i][3]!=0)
			{
				flagA=false;
				break;
			}
		}
		if (flagA)
		{
			int ans = 0;
			for (int i = 1; i <= n; i++) A[i]=a[i][1];
			sort(A+1,A+n+1);
			for (int i = n; i > n/2; i--) ans+=A[i];
			writech(ans,'\n');
			continue;
		}
		bool flagB = true;
		for (int i = 1; i <= n; i++)
		{
			if (a[i][3]!=0)
			{
				flagB=false;
				break;
			}
		}
		if (flagB)
		{
			int ans = 0;
			vector<int> aa,bb;
			for (int i = 1; i <= n; i++)
			{
				if (a[i][1]>a[i][2]) ans+=a[i][1],aa.push_back(a[i][1]-a[i][2]);
				else ans+=a[i][2],bb.push_back(a[i][2]-a[i][1]);
			}
			int la=aa.size(),lb=bb.size();
			if (la>n/2)
			{
				sort(aa.begin(),aa.end());
				for (int i = 0; i < la-n/2; i++) ans-=aa[i];
			}
			else if (lb>n/2)
			{
				sort(bb.begin(),bb.end());
				for (int i = 0; i < lb-n/2; i++) ans-=bb[i];
			}
			writech(ans,'\n');
			continue;
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k <= n; k++)
					dp[i][j][k]=0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j>n/2) break;
				for (int k = 0; k <= i; k++)
				{
					if (k>n/2||j+k>i) break;
					int l = i-j-k;
					if (l>n/2) continue;
					if (j>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if (k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if (l>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n/2; i++)
		{
			for (int j = 0; j <= n/2; j++)
			{
				int k = n-i-j;
				if (k>n/2) continue;
				ans=max(ans,dp[n][i][j]);
			}
		}
		writech(ans,'\n');
	}
	return 0;
}

