#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;s[i];i++){
		mp[s[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i+'0'];j++){
			cout<<char(i+'0');
		}
	}
	return 0;
}