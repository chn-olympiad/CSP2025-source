#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e5 + 10;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n,A = 0;
		cin >> n;
		int a[n + 1][3];
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j < 3;j++)
			{
				cin >> a[i][j];
				if(a[i][1] == 0 && a[i][2] == 0)
					A++;
			}	
		}
		if(A == n)
		{
			int f[n + 1],sum = 0;
			for(int i = 1;i <= n;i++)
				f[i] = a[i][1];
			sort(f + 1,f + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++)
				sum += f[i];
			cout << sum << '\n';
			continue;
		}
		if(n == 2)
		{
			int f[3][3],ans = -1,cnt[3];
			for(int i = 0;i < 3;i++)
				for(int j = 0;j < 3;j++)
					f[i][j] = a[1][i] + a[2][j];
//			for(int i = 0;i < 3;i++)
//				for(int j = 0;j < 3;j++)
//					cout << f[i][j] << ' ';
			for(int i = 0;i < 3;i++)
				for(int j = 0;j < 3;j++)
				{
					cnt[0] = cnt[1] = cnt[2] = 0;
					cnt[i]++,cnt[j]++;
					if(f[i][j] > ans && cnt[i] <= n / 2 && cnt[j] <= n / 2)
						ans = f[i][j];
				}
			cout << ans << '\n';
			continue;
		}
		if(n == 4)
		{
			int f[3][3][3][3],ans = -1,cnt[3];
			for(int i = 0;i < 3;i++)
				for(int i1 = 0;i1 < 3;i1++)
					for(int i2 = 0;i2 < 3;i2++)
						for(int i3 = 0;i3 < 3;i3++)
							f[i][i1][i2][i3] = a[1][i] + a[2][i1] + a[3][i2] + a[4][i3];
			for(int i = 0;i < 3;i++)
				for(int i1 = 0;i1 < 3;i1++)
					for(int i2 = 0;i2 < 3;i2++)
						for(int i3 = 0;i3 < 3;i3++)
						{
							cnt[0] = cnt[1] = cnt[2] = 0;
							cnt[i]++,cnt[i1]++,cnt[i2]++,cnt[i3]++; 
							if(f[i][i1][i2][i3] > ans && cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
								ans = f[i][i1][i2][i3];
						 } 				
			cout << ans <<'\n';
			continue;
		}
		if(n == 10)
		{
			int f[3][3][3][3][3][3][3][3][3][3],ans = -1,cnt[3];
			for(int i = 0;i < 3;i++)
				for(int i1 = 0;i1 < 3;i1++)
					for(int i2 = 0;i2 < 3;i2++)
						for(int i3 = 0;i3 < 3;i3++)
							for(int i4 = 0;i4 < 3;i4++)
								for(int i5 = 0;i5 < 3;i5++)
									for(int i6 = 0;i6 < 3;i6++)
										for(int i7 = 0;i7 < 3;i7++)
											for(int i8 = 0;i8 < 3;i8++)
												for(int i9 = 0;i9 < 3;i9++)
													f[i][i1][i2][i3][i4][i5][i6][i7][i8][i9] = a[1][i] + a[2][i1] + a[3][i2] + a[4][i3] + a[5][i4] + a[6][i5] + a[7][i6] + a[8][i7] + a[9][i8] + a[10][i9];
			for(int i = 0;i < 3;i++)
				for(int i1 = 0;i1 < 3;i1++)
					for(int i2 = 0;i2 < 3;i2++)
						for(int i3 = 0;i3 < 3;i3++)
							for(int i4 = 0;i4 < 3;i4++)
								for(int i5 = 0;i5 < 3;i5++)
									for(int i6 = 0;i6 < 3;i6++)
										for(int i7 = 0;i7 < 3;i7++)
											for(int i8 = 0;i8 < 3;i8++)
												for(int i9 = 0;i9 < 3;i9++)
												{
													cnt[0] = cnt[1] = cnt[2] = 0;
													cnt[i]++;cnt[i1]++;cnt[i2]++;cnt[i3]++;cnt[i4]++;
													cnt[i5]++;cnt[i6]++;cnt[i7]++;cnt[i8]++;cnt[i9]++;
													if(f[i][i1][i2][i3][i4][i5][i6][i7][i8][i9] > ans && cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
														ans = f[i][i1][i2][i3][i4][i5][i6][i7][i8][i9];
												}
			cout << ans <<'\n';
			continue;
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/
