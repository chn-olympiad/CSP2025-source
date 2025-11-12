#include <bits/stdc++.h>
using namespace std;
string s;
vector <int> a;
bool cmp(int x,int y)
{
	return x > y;
}
int len,n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.length();
	for(int i = 0; i < len; i ++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			a.push_back(s[i] - '0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(auto i:a)
	{
		cout << i;
	}
	
	return 0;
}
