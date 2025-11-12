#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str;
	int s[N], j = 0;
	int cnt = 0;
	cin >> str;
	cnt = str.size();
	for(int i = 0; i < cnt; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			s[j] = int(str[i]) - 48;
			//cout << s[i];
			j++;
		}
	}
	sort(s, s + j);
	for(int i = j - 1; i >= 0; i--)
		cout << s[i];
	return 0;
}
