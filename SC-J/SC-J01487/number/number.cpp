#include<bits/stdc++.h>

using namespace std;

map<char,string> mp;
string s;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i*1ull<s.size();i++){
		
		if(s[i]>='0'&&s[i]<='9'){
			
			mp[s[i]]+=s[i];
			
		}
		
	}
	
	for(int i='9';i>='0';i--){
		
		if(mp.count(i)){
			
			cout<<mp[i];
			
		}
		
	}
	
	return 0;
	
}