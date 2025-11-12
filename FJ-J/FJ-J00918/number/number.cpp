#include<bits/stdc++.h>
using namespace std;
int o[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0'){
			o[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		if(o[i])
		for(int l=1;l<=o[i];++l){
			cout<<i;
		}
	}
	return 0;
} 
