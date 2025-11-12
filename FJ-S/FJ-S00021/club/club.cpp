#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair <int,int> PII;
int t,n;
int a[100005][4];
vector <int> ans[4];
PII dp[100005];
int cnt[6];
int person[4];
int x,y,z;
int aa[100005];
bool cmp(PII p,PII q)
{
	return a[p.first][x]-a[p.first][p.second]<a[q.first][x]-a[q.first][q.second];
}
inline void sw_3(int ttt)
{
	int sum=person[x]-n/2;
	for (int i=0;i<person[x];i++)
	{
		int sc=ans[x][i];
		int dy=a[sc][x]-a[sc][y],dz=a[sc][x]-a[sc][z];
		if (dy<=dz)
		{
			dp[i].first=sc;
			dp[i].second=y;
		}
		else
		{
			dp[i].first=sc;
			dp[i].second=z;
		}
	}
	sort (dp,dp+person[x],cmp);
	for (int i=0;i<sum;i++)
	{
		cnt[ttt]-=(a[dp[i].first][x]-a[dp[i].first][dp[i].second]);
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin >> t;
	for (int tt=1;tt<=t;tt++)
	{
		cin >> n;
		for (int i=1;i<=n;i++)
		{
			ans[i].clear();
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				cin >> a[i][j];
			}
			int xx=a[i][1],yy=a[i][2],zz=a[i][3];
			if (xx>=yy)
			{
				if (xx>=zz)
				{
					ans[1].push_back(i);
					cnt[tt]+=a[i][1];
				}
				else
				{
					ans[3].push_back(i);
					cnt[tt]+=a[i][3];
				}
			}
			else
			{
				if (yy>=zz)
				{
					ans[2].push_back(i);
					cnt[tt]+=a[i][2];
				}
				else
				{
					ans[3].push_back(i);
					cnt[tt]+=a[i][3];
				}
			} 
		}
		person[1]=ans[1].size();
		person[2]=ans[2].size();
		person[3]=ans[3].size();
		//cout << ans[1][0] << ans[1][1] << endl;
		//for (int i=1;i<=3;i++)
		//{
		//	for (int j=1;j<=person[i];j++)
		//		cout << ans[i][j] << " ";
		//	cout << endl;
		//}
		//cout << person[1] << " " << person[2] << " " << person[3] << endl;
		for (int i=1;i<=3;i++)
		{
			if (person[i]>n/2)
			{
				x=i;
				switch (i)
				{
					case 1:y=2,z=3;break;
					case 2:y=1,z=3;break;
					case 3:y=1,z=2;break;
				}
				if (n<=200)
				{
					sw_3(tt);
					break;
				}
				else
				{
					int s=1;
					for (int j=1;j<=n;j++)
					{
						if (a[j][2]!=0)
						{
							s=2;
							break;
						}
					}
					if (s==1)
					{
						for (int j=1;j<=n;j++)
							aa[j]=a[j][1];
						sort(aa+1,aa+n+1);
						for (int j=1;j<=n/2;j++)
							cnt[tt]-=aa[j];
					}
					else if (s==2)
					{
						sw_3(tt);
						break;
					}
				}
			}
		}
	}
	for (int i=1;i<=t;i++)
	{
		cout << cnt[i] << endl;
	}
	return 0;
}
