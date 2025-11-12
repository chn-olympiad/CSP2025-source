#include <bits/stdc++.h>
using namespace std;
bool flag = 1;
string s;
vector <int> v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	for(int i = v.size()-1;i >= 0;i--)
	{
		if(v[i] != 0 || flag == 0)
		{
			cout << v[i];
			flag =  0;
		}
	}
	if(flag==1)
	{
		cout << 0;
	}
	return 0;
}
