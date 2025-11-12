#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
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
		if('0' <= s[i] && s[i] <= '9') a.push_back(s[i]-'0'); 
	}
	sort(a.begin(),a.end(),greater<int>());
	for(auto i:a) cout << i;
	return 0;
}

