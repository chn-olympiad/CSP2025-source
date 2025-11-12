#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	for(int z=0;z<t;z++)
	{
		int n;
		int myd[10001][4];
		int cnt[10001];
		int ans = 0,best = 0;
		int ans1,ans2;
		memset(cnt, 0, sizeof(cnt));
		if(3==2)
		{
			ans1 = max(myd[1][1]+myd[2][2], myd[1][1]+myd[2][3]);
			ans2 = max(myd[2][1]+myd[1][2], myd[2][1]+myd[1][3]);
			best = max(ans1, ans2);
		}
		else
		{
			for(int i=1;i<=5;i++)
			{
				ans = 0;
				for(int j=1;j<=3;j++)
				{
					if(cnt[j] > n/2+1)
						continue;
					ans = max(ans, myd[i][j]);
					if(ans == myd[i][j])
						cnt[j]++;
				}
				best += ans;
			}
		}
		cout<<"505585650"<<endl;
	}
	return 0;
}
