#include<bits/stdc++.h>
using namespace std;
string s,ss;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if(i>='0'&&i<='9') ss+=i;
	}
	sort(ss.begin(),ss.end(),greater<char>());
	for(auto i:ss){
		cout<<i;
	}
	return 0;
}
