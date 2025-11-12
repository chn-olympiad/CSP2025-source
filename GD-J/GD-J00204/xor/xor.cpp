#include <iostream>
using namespace std;

int nums[1000001] = {}, n, k, a, scole[2] = {}, cnt = 0; //a only for input
int dp[1000001] = {}; //dp[i][j]表示区间[i, j]的异或和
bool isMeet(int a, int b, int c, int d)
{
	return !(a < c && b < c || a > d && b > d); 
}

void renew(int i, int j)
{
	if (!scole[0]) // scole hasn't changed yet
	{
		scole[0] = j;
		scole[1] = i;
		cnt++;
		return;
	}
	if (isMeet(i, j, scole[0], scole[1])) //not change
	{
		if (cnt == 1)
		{
			int a = i - j, b = scole[1] - scole[0];
			scole[0] = (a > b) ? scole[0] : j;
			scole[1] = (a > b) ? scole[1] : i;
		}
		return;
	}
	//renew
	scole[0] = min(j, scole[0]);
	scole[1] = max(i, scole[1]);
	cnt++;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a; //recent number
		dp[i] = a;
		if (dp[i] == k)
			renew(i, i);
		for (int j = 1; j < i; j++) //each : [j, i]
		{
			dp[j] ^= a;
			if (dp[j] == k)
			{
				renew(i, j);
			}	
		}
	}
	cout << cnt;
	
	return 0;
}
