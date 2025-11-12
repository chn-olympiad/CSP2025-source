/*
./compile number a
./number
*/
#include<bits/stdc++.h>
#define allof(o) (o).begin(),(o).end()
using namespace std;
string s,t;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(auto c:s)
		if(isdigit(c))
			t+=c;
	sort(allof(t));
	reverse(allof(t));
	cout<<t;
	return 0;
}