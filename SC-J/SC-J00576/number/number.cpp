#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin>>s;
	vector<int> v;
	for(auto c:s)
	{
		if('0'<=c && c<='9')
			v.push_back(c-'0');
	}
	sort(v.begin(),v.end(),greater<int>());
	for(auto x:v) cout<<x;
	return 0;
}