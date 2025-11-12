#include <iostream>
#include <algorithm>
using namespace std;

int numbers[1000005];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9') 
			numbers[cnt++] = s[i] - '0';
	sort(numbers, numbers + cnt, cmp);
	for (int i = 0; i < cnt; i++)
		cout << numbers[i];
	cout << endl;
	return 0;
}
