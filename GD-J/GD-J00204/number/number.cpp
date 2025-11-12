#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
	return (a > b);
}

int nums[1000001] = {}, ind = 0;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	vector<int> choice = {};
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <='9')
			nums[ind++] = s[i] - '0';
	}
	sort(nums, nums + ind, cmp);
	for (int i = 0, j = ind - 1; i < ind; i++, j--)
	{
		cout << nums[i];
	}
	
	return 0;
} 
