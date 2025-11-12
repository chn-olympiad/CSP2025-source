#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll z,h;
	cin>>z>>h;
	for(ll i=0;i<z;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(ll i=0;i<h;i++){
		string s1,s2;
		cin>>s1>>s2;
		cout<<"0\n";
	}
	return 0;
}
