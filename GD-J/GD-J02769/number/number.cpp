#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s, ans = "";cin >> s;
	long long freq[10] = {};
	for(char c : s)
	{
		if(c >= '0' && c <= '9')
		{
			++freq[c - '0'];
		}
	}
	for(int i = 9; i >= 0; --i)
	{
		while(freq[i] > 0)
		{
			ans += (i + '0');
			--freq[i];
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
