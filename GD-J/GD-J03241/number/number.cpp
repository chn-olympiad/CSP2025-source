#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<char> e;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))e.push_back(s[i]);
	sort(e.begin(),e.end(),greater<char>());
	for(auto x:e)
		cout<<x;
	return 0;
}
