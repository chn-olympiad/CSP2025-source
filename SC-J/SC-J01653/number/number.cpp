#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> ve;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			ve.push_back((int)(s[i]-'0'));
	sort(ve.begin(),ve.end());
	for(int i=ve.size()-1;i>=0;i--)
		cout<<ve[i];
	return 0;
} 