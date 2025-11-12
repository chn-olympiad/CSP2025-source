#include <bits/stdc++.h>
using namespace std;
int e[1000005];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j_me = 0,ans = 0,cheng = 1;
	cin >> s;
	for(int i = 0;i < s.length();i++)
	{
		if('0' <= (char)s[i] && (char)s[i] <= '9')
		{
			e[j_me] = (int)s[i] - '0';
			j_me++;
		}
	}
	sort(e,e + j_me - 1,cmp);
	for(int i = 0;i < j_me;i++)
	{
		ans += e[j_me - i - 1] * cheng;
		cheng *= 10;
	}
	cout << ans;
	
	return 0;
}
