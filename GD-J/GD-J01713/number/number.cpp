#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<char> ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for (int i = 1; i <= n; i++)
	{
		if (s[i]>='0'&&s[i]<='9') ans.push_back(s[i]);
	}
	sort(ans.begin(),ans.end());
	for (int i = ans.size()-1; i >= 0; i--) cout<<ans[i];
	return 0;
}

