#include <bits/stdc++.h>
using namespace std;
long long f;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	char st[1000005];
	cin >> s;
	for(long long i = 0; i < s.size(); i++)
	{
		char k = s[i];
		if(('0' <= k) && (k <= '9'))
		{
			st[++f] = k;
		}
	}
	sort(st +1, st +f + 1);
	while(f != 0)
	{
		cout << st[f];
		f--;
	}
	return 0;
}
