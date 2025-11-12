#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
map<ll,ll>mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')mp[s[i]-'0']++;
	}
	for(ll i=9;i>=0;i--){
		while(mp[i]!=0){
			cout<<i;
			mp[i]--;
		}
	}
	return 0;
}
