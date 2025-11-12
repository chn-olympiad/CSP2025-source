#include<bits/stdc++.h>
using namespace std;
map<int,long long>mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')mp[s[i]-'0']++; 
	}
	for(int i=9;i>=0;i--){
		while(mp[i]){
			cout<<i;
			mp[i]--;
		}
	}
	return 0;
}
