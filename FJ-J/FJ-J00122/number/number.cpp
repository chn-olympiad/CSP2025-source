#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	map<int,int> mp;
	string s;
	cin>>s;
	for(int i=0;i<int(s.length());i++) mp[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=0;j<mp[i];j++) cout<<i;
	}
	return 0;
}
