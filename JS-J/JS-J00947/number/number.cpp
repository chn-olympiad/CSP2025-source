#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	for(char c:s)
		if(isdigit(c))ans+=c;
	sort(ans.begin(),ans.end(),greater<char>());
	cout<<ans<<'\n';
	return 0;
}
//Finish debug on 9:15.
//AK,maybe.