#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin>>s;
	vector<char>v;
	for(auto c:s)
		if(isdigit(c))
			v.push_back(c);
	sort(v.begin(),v.end(),greater<char>());
	if(v[0]=='0'){
		cout<<0<<'\n';
		return 0;
	}
	for(auto c:v)
		cout<<c;
	cout<<'\n';
	return 0;
}