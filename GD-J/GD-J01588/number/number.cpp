#include <bits/stdc++.h>

using namespace std;

string s;
bool flag_0 = true;
int box[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			box[s[i] - '0'] ++;
			if (s[i] != '0') flag_0 = false;
		}
	}
	if (flag_0) cout << 0;
	else
	{
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 1; j <= box[i]; j++)
				cout << i;	
		}
	}
	return 0;
}
//O(len)
