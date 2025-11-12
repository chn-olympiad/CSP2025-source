#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll cnt[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll len = s.size();
	for(ll i = 0;i < len;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt[s[i] - '0']++;
		}
	}
	for(ll i = 9;i >= 0;i--)
	{
		while(cnt[i])
		{
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}
