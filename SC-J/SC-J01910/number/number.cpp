#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
vector<ll>a;
bool qwq(char a){
	return '0'<=a&&a<='9';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++)
		if(qwq(s[i]))
			a.push_back(s[i]-'0');
	sort(a.begin(),a.end(),greater<ll>());
	for(ll i=0;i<a.size();i++)
		cout<<a[i];
	return 0;
}