#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int box[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	string s;
	cin >> s;
	int t = s.size();
	for(int i = 0;i < t;i++)
	{
		char c = s[i];
		if (c == '1') box[1]++;
		else if (c == '2') box[2]++;
		else if (c == '3') box[3]++;
		else if (c == '4') box[4]++;
		else if (c == '5') box[5]++;
		else if (c == '6') box[6]++;
		else if (c == '7') box[7]++;
		else if (c == '8') box[8]++;
		else if (c == '9') box[9]++;
		else if (c == '0') box[0]++;
		
	}
	for (int i = 9;i >= 0;i--)
	{
		for (int j = 1;j <= box[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
