#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
		if(isdigit(s[i]))
			v.push_back(int(s[i]-48));
	sort(v.begin(),v.end(),greater<int>());
	for(int i:v) 
		cout<<i;
	return 0;
} 
