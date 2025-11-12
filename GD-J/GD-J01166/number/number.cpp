#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	for(ll i=0;i<s.size();i++)
		if(isdigit(s[i]))
			ans.push_back(s[i]);
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
}

