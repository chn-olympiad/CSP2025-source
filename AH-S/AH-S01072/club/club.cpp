#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int x, y, z;
}a[100005];
int dp[105][105][205];
bool cmpx(stu a, stu b)
{
	return a.x>b.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
		int n;
		cin >> n;
		int ansx=0, ansy=0, ansz=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			ansx+=(a[i].x!=0);
			ansy+=(a[i].y!=0);
			ansz+=(a[i].z!=0);
		}
		if(ansy+ansz==0)
		{
			int sum=0;
			sort(a+1,a+n+1,cmpx);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].x;
			}
			cout << sum << "\n";
			continue;
		}
		if(n<=200)
		{
			memset(dp,0,sizeof(dp));
			for(int len=1;len<=n;len++)
			{
				for(int i=0;i<=min(len,n/2);i++)
				{
					for(int j=0;j<=min(len-i,n/2);j++)
					{
						if(len-(i+j)>n/2) continue;
						if(i+j<len) dp[i][j][len]=max(dp[i][j][len],dp[i][j][len-1]+a[len].z);
						if(i>0) dp[i][j][len]=max(dp[i][j][len],dp[i-1][j][len-1]+a[len].x);
						if(j>0) dp[i][j][len]=max(dp[i][j][len],dp[i][j-1][len-1]+a[len].y);
					}
				}
			}
			int Max=0;
			for(int i=0;i<=n/2;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					Max=max(Max,dp[i][j][n]);
				}
			}
			cout << Max << "\n";
		}
	}
    return 0;
}
/*
1
4
1 0 0
1 0 0
2 0 0
2 0 0
*/
