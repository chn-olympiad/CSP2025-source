#include<bits/stdc++.h>
using namespace std;
int nums[1000005];
int main()
{
	freopen ("number.in", "r",stdin);
	freopen ("number.out", "w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	int xb = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			nums[xb++] = s[i] - '0';
		}
	}
	for (int i = 0; i < xb; i++)
	{
		for (int j = i + 1; j < xb; j++)
		{
			if (nums[i] < nums[j])
				swap (nums[i], nums[j]);
		}
	}
	int answer = 0;
	for (int i = 0; i < xb; i++)
	{
		answer *= 10;
		answer += nums[i];
	}
	cout << answer;
	return 0;
}
