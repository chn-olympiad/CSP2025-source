#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	map<int,int>mp;
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		mp[s[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=mp[i+48];j>=1;j--)cout<<i;
	}
	return 0;
}