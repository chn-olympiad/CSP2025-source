#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
stack<ll> c;
ll ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=0;s[i]<='9';i++){
		ll n=s[i]-'0';
		c.push(n);
	}
	while(c.size()){
		cout<<c.top();
		c.pop();
	}
	return 0;
}
