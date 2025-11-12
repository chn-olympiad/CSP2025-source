
#include <bits/stdc++.h>

using namespace std;
int n,t;

int a[200005][5];
int p1 = 1,p2 = 1,p3  = 1,dp[100][100][100],cntp,cntk,cntj,ans = -1;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        int p1 = 1,p2 = 1,p3  = 1,ans = -1;
        int cntp = 0,cntk = 0,cntj = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        int p = 1;
        int j = 1;
        int k = 1;

        for(int i = 1;i <= n;i++)
        {
        	int mss1 = -1,mss2 = -1,mss3 = -1;

        	for(int j1 = 1;j1 <= 3;j1++)
        	{

        		mss1 = max(dp[p-1][j][k] + a[i][j1],mss1);

			}
			for(int j1 = 1;j1 <= 3;j1++)
        	{

        		mss2 = max(dp[p][j - 1][k] + a[i][j1],mss2);

			}
			for(int j1 = 1;j1 <= 3;j1++)
        	{

        		mss3 = max(dp[p][j][k - 1] + a[i][j1],mss3);

			}

			if(p1 == 1 && max(mss1,max(mss2,mss3)) == mss1)
			{

				dp[p][j][k] = mss1;

				int t1 = dp[p][j-1][k] + a[i][2];
				int t2 = dp[p][j][k-1] + a[i][3];


//				cout << 11 << endl;
				cntp++;
				p++;
				dp[p][j-1][k] = t1;
				dp[p][j][k-1] = t2;
//				cout << i << " **" << dp[p][j-1][k] << endl;
			}
			else if(p2 == 1)
			{
//				cout << "'**" << endl;
				if(p1 == 0)
				{
					if(p3 != 0 && max(mss2,mss3) == mss2)
					{
						dp[p][j][k] = mss2;
						ans = max(ans,dp[p][j][k]);

						int t11 = dp[p-1][j][k] + a[i][1];
						int t22 = dp[p][j][k-1] + a[i][3];
						cntj++;
//						cout << 12 << endl;
						j++;
						dp[p-1][j][k] = t11 ;
						dp[p][j][k-1] = t22 ;
					}
					else if(p3 == 0)
					{
						dp[p][j][k] = mss2;
						ans = max(ans,dp[p][j][k]);

						int t11 = dp[p-1][j][k] + a[i][1];
						int t22 = dp[p][j][k-1] + a[i][3];
						cntj++;
						j++;
						cout << 12 << endl;
						dp[p-1][j][k] = t11 ;
						dp[p][j][k-1] = t22 ;
					}

				}






			}
			else if (p3 == 1 )
			{
				dp[p][j][k] = mss3;
				ans = max(ans,dp[p][j][k]);
//				cout << i << " " << ans << endl;
				int t111 = dp[p-1][j][k] + a[i][1];
				int t222 = dp[p][j-1][k] + a[i][2];
//				cout << 13 << endl;
				k++;
				cntk++;
				dp[p-1][j][k] = t111;
				dp[p][j-1][k] = t222 ;
			}
			if(cntp >= n / 2)
        	{
        		p1 = 0;
			}
			if(cntj >= n / 2)
			{
				p2 = 0;
			}
			if(cntk >= n / 2)
			{
				p3 = 0;
			}
        }
        cout << ans << endl;

    }

    return 0;
}
