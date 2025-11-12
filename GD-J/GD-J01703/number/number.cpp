#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int cmp(char a,char b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i ++)
	{
		if(s[i] >= 47 && s[i] <= 58)
		{
			ans += s[i];
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout << ans;
	return 0;
}
