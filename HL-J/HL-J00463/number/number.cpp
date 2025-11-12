#include <bits/stdc++.h>
using namespace std;
int main()
{
	//HL-J00463-number
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	priority_queue<long long> num;
	for(auto x : s)
	{
		if(x >= '0' && x <= '9')
		{
			num.push(x);
		}
	}
	long long len = num.size();
	for(long long i = 1 ; i <= len ; i ++)
	{
		long long first = num.top() - 48;
		printf("%d", first);
		num.pop();
	}
	return 0;
}