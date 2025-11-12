#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++) mp[i]=0;
	cin>>s;
	for(size_t i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0') mp[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++) printf("%d",i);
	}
	return 0;
}
