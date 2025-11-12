#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			ans+=s[i];
		}
	}
	sort(ans.begin(),ans.end(),greater<char>());
	cout<<ans;
	return 0;
}
