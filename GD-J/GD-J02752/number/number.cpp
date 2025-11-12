#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			mp[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(mp[i]){
			cout<<i;
			mp[i]--;
		} 
	}
	return 0; 
} 
