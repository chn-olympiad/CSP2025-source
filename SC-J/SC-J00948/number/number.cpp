#include <bits/stdc++.h>
using namespace std;
string s;
long long vis[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i ++)
	{
		if('0' <= s[i] && s[i] <= '9')
		    vis[s[i] - '0']++;
	}
	for(int i = 9;i >= 0;i --)
	{
		while(vis[i] > 0)
		{
			cout << i;
			vis[i]--;
		}
	}
    return 0;
}