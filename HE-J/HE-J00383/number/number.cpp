#include<bits/stdc++.h>
using namespace std;
string s,t="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (auto c:s)
		if (c>='0'&&c<='9')
			t+=c;
	sort(t.begin(),t.end(),greater<char>());
	cout<<t;
	return 0;
}
