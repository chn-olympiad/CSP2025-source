#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	map<char,int> mp;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			mp[s[i]]++;
		}
	}
	for(int i=9;i>=0;i--){
		char a=char(i+'0');
		for(int j=0;j<mp[a];j++){
			if(ans!="0"){
				ans+=a;
			}
		}
	}
	cout << ans;
	return 0;
}
