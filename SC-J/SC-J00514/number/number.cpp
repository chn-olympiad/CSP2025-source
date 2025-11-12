#include<bits/stdc++.h>
using namespace std;

string s;
string t;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s;
	for(char i:s) if('0'<=i&&i<='9') t.push_back(i);
	sort(t.begin(),t.end(),greater<char>());
	cout<<t;
	return 0;
}