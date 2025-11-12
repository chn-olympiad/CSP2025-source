#include <bits/stdc++.h>
using namespace std; 
int nums[15]; 
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	char ch; 
	while(cin >> ch)
	{
		if('0' <= ch && ch <= '9')
		{
			nums[ch - '0']++; 
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		while(nums[i]--)
		{
			cout << i; 
		}
	}
	return 0; 
}

