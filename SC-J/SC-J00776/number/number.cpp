#include <bits/stdc++.h>
using namespace std;

string s;
long long cnt[15]; 

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	
	for (int i = 0; i < s.size(); ++ i)
		if (s[i] >= '0' && s[i] <= '9') ++ cnt[int(s[i] - '0')];

	for (int i = 9; i >= 0; -- i)
		while (cnt[i] --) cout << i;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
