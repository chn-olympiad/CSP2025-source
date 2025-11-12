#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
vector<int> vans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		if('0'<=s[i]&&s[i]<='9') vans.emplace_back(s[i]-'0');
	sort(vans.begin(),vans.end());
	for(int i=(int)vans.size()-1;i>=0;i--) cout<<vans[i];
	return 0;
}
