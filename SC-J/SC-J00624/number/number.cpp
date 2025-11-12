//愿此行，终抵群星
//rp++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll num[1000005] , cnt;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	ll len = s.length();
	for(int i = 0;i < len;i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			num[++cnt] = s[i] - '0';
		}
	}
	sort(num + 1 , num + cnt + 1);
	if(num[cnt] == 0)
	{
		cout << 0;
	}
	else
	{
		for(int i = cnt;i >= 1;i--)
		{
			cout  << num[i];
		}
	}
	return 0;
}