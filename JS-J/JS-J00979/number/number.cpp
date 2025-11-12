#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	vector<int> nums(10);
	char a;

	while((a = getchar()) != -1)
		if ('0' <= a && a <= '9')
			nums[a-'0']++;

	for (int i = 9; i >= 0; --i)
		while (nums[i]--)
			cout << i;
	
	cout << '\n';

	return 0;
}