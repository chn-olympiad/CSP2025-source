#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
map<char,int> mp;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			mp[s[i]]++;
		}
	}
	for(int i='9';i>='0';i--){
		while(mp[i]!=0){
			cout<<i-'0';
			mp[i]--;
		}
	}
	return 0;
}
