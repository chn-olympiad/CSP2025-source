#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end(),greater<char>());
	for(auto e:s)
		if(isdigit(e))
			cout<<e;
}
