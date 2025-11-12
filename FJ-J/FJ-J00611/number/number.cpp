#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<ll> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a.push_back(s[i]-'0');
	}
	sort(a.begin(),a.end(),greater<ll>());
	for(ll i=0;i<a.size();i++) cout<<a[i];
	return 0;
}
