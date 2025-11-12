#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<char,ll>m;
string s,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m[s[i]]++;
		}
	}
	for(auto i:m){
		for(ll j=1;j<=i.second;j++){
			ans+=i.first;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}
