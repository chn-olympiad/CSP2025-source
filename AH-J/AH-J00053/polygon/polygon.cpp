#include<bits/stdc++.h>
using namespace std;
const int N = 5000;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 3) 
	{
		if(n < 3) 
		{
			cout << 0;
			return 0;
		}
		int Max = INT_MIN, sum = 0;
		for(int i = 1; i <= n; i++) 
		{
			sum += a[i];
			if(a[i] > Max) Max = a[i];
		}
		if(sum > 2 * Max) 
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	if(n <= 10) 
	{
		int sum = 0;
		sort(a + 1, a + 1 + n);
		int ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0, ans7 = 0, ans8 = 0, ans9 = 0, ans10 = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				for(int k = j + 1; j <= n; j++)
				{
					sum = a[i] + a[j] + a[k];
					if(sum > 2 * a[k]) ans3++;
					sum = 0;
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				for(int k = j + 1; j <= n; j++)
				{
					for(int g = k + 1; g <= n; g++)
					{
						sum = a[i] + a[j] + a[k] + a[g];
						if(sum > 2 * a[g]) ans4++;
						sum = 0;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				for(int k = j + 1; j <= n; j++)
				{
					for(int g = k + 1; g <= n; g++)
					{
						for(int h = g + 1; h <= n; h++)
						{
							sum = a[i] + a[j] + a[k] + a[g] + a[h];
							if(sum > 2 * a[h]) ans5++;
							sum = 0;
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				for(int k = j + 1; j <= n; j++)
				{
					for(int g = k + 1; g <= n; g++)
					{
						for(int h = g + 1; h <= n; h++)
						{
							for(int j = h + 1; j <= n; j++)
							{
								sum = a[i] + a[j] + a[k] + a[g] + a[h] + a[j];
								if(sum > 2 * a[j]) ans6++;
								sum = 0;
							}
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				for(int k = j + 1; j <= n; j++)
				{
					for(int g = k + 1; g <= n; g++)
					{
						for(int h = g + 1; h <= n; h++)
						{
							for(int j = h + 1; j <= n; j++)
							{
								for(int l = j + 1; l <= n; l++)
								{
									sum = a[i] + a[j] + a[k] + a[g] + a[h] + a[j] + a[l];
									if(sum > 2 * a[l]) ans7++;
									sum = 0;
								}
							}
						}
					}
				}
			}
		}
		sum = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8];
		if(sum > 2 * a[8]) ans8++;
		sum = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[9];
		if(sum > 2 * a[9]) ans8++;
		sum = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[10];
		if(sum > 2 * a[10]) ans8++;
		sum = a[2] + a[9] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8];
		if(sum > 2 * a[9]) ans8++;
		sum = a[2] + a[10] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8];
		if(sum > 2 * a[10]) ans8++;
		sum = a[3] + a[10] + a[9] + a[4] + a[5] + a[6] + a[7] + a[8];
		if(sum > 2 * a[10]) ans8++;
		sum = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9];
		if(sum > 2 * a[9]) ans9++;
		sum = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[10];
		if(sum > 2 * a[10]) ans9++;
		sum = a[2] + a[10] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9];
		if(sum > 2 * a[10]) ans9++;
		sum = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9] + a[10];
		if(sum > 2 * a[10]) ans10++;
		if(n == 3) cout << ans3;
		if(n == 4) cout << ans3 +ans4;
		if(n == 5) cout << ans3 +ans4 + ans5;
		if(n == 6) cout << ans3 + ans4 +ans5+ ans6;
		if(n == 7) cout << ans3 + ans4 +ans5+ ans6 + ans7;
		if(n == 8) cout << ans3 + ans4 +ans5+ ans6 + ans7+ ans8;
		if(n == 9) cout << ans3 + ans4 +ans5+ ans6 + ans7+ ans8 + ans9;
		if(n == 10) cout << ans3 + ans4 +ans5+ ans6 + ans7+ ans8 + ans9 + ans10;
	}
	return 0;
}
