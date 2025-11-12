#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int num[1000005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cur = 1;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			num[cur] = s[i] - '0';
			cur++;
		}
	}
	sort(num + 1, num + cur + 1, cmp);
	for(int i = 1; i < cur; i++)
	{
		cout << num[i];
	}
	return 0;
}
