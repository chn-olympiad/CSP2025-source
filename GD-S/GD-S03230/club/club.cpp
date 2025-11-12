#include<bits/stdc++.h>
using namespace std;
const int MN=1e5+10;
int T;
int n=0;
int mord1=1;
struct stu
{
	int a[4];
	int d[4];
	int no;
};
int max3(int x1, int x2, int x3)
{
	return max(max(x1,x2),x3);
}
int min3(int x1, int x2, int x3)
{
	return min(min(x1,x2),x3);
}
int mid3(int x1, int x2, int x3)
{
	int u=max3(x1, x2, x3);
	int d=min3(x1, x2, x3);
	if(x1 == u || x1 == d) x1=0;
	if(x2 == u || x2 == d) x2=0;
	if(x3 == u || x3 == d) x3=0;
	return max3(x1, x2, x3);
}

bool cmp1(stu x, stu y)
{
	return x.a[mord1]-x.a[x.d[2]] > y.a[mord1]-y.a[x.d[2]];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		int ans=0;
		cin >> n;
		stu s[1000];
		for(int i=1;i<=n;i++)
		{
			cin >> s[i].a[1] >> s[i].a[2] >> s[i].a[3];
			s[i].d[1] = max3(s[i].a[1], s[i].a[2], s[i].a[3]);
			s[i].d[2] = mid3(s[i].a[1], s[i].a[2], s[i].a[3]);
			s[i].d[3] = min3(s[i].a[1], s[i].a[2], s[i].a[3]);
			s[i].no=i;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					if(s[i].d[j]==s[i].a[k])
					{
						s[i].d[j]=k;
						break;
					}	
				}
			}
		}
		int d1[4]={};
		for(int i=1;i<=n;i++)
		{
			d1[s[i].d[1]]++;
		}
		if(d1[2]>d1[1] && d1[2]>d1[3]) mord1=2;
		if(d1[3]>d1[1] && d1[3]>d1[2]) mord1=3;
		sort(s+1, s+n+1, cmp1);
		int dp[MN][5]={{},{0,s[1].a[1], s[1].a[2], s[1].a[3]}};
		int cnt[4]={};
		int pc;
		for(int i=2;i<=n;i++)
		{
			pc=0;
			for(int k=1;k<=3;k++)
			{
				if(cnt[k]>=n/2) continue;
				if(dp[i-1][pc] < dp[i-1][k]) pc=k;
			}
			cnt[pc]++;
			for(int j=1;j<=3;j++)
			{
				if(cnt[pc] < n/2 || (j!=pc && cnt[j]<n/2)) dp[i][j]=dp[i-1][pc]+s[i].a[j];
				else if(cnt[s[i-1].d[2]] < n/2) dp[i][j]= dp[i-1][s[i-1].d[2]]+s[i].a[j];
				else dp[i][j]=dp[i-1][s[i-1].d[3]]+s[i].a[j];
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=3;j++)
//			{
//				cout << dp[i][j] << ' ';
//			}
//			cout << endl;
//		}
		for(int i=1;i<=3;i++) ans=max(ans, dp[n][i]);
		cout << ans << endl;
	}
	return 0;
}
