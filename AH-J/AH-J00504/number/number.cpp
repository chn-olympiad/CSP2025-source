#include<bits/stdc++.h>
using namespace std;
string s;
map<char,int> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			mp[s[i]]++;
		}
	}
	for(char i='9';i>='0';i--){
		for(int j=1;j<=mp[i];j++){
			cout<<i;
		}
	}
	return 0;
}
