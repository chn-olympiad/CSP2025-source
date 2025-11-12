#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e1 + 1;
int bucket[maxn];
string ans;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(isdigit(s[i]))
		{
			bucket[s[i] ^ 48]++;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= bucket[i]; j++)
		{
			ans += (i + 48);
		}
	}
	cout << ans;
	return 0;
}
