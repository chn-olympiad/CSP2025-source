#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<int> nums;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	
	for (char c : s)
	{
		if (c >= '0' && c <= '9')
		{
			nums.push_back(c - '0');
		}
	}
	
	sort(nums.begin(), nums.end(), [&](const int &a, const int &b)
	{
		return a > b;
	});
	
	if (nums[0] == '0')
	{
		printf("0\n");
		return 0;
	}
	
	for (int n : nums)
	{
		printf("%d", n); 
	}
	printf("\n");
	return 0;
}
