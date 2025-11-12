#include<bits/stdc++.h>
using namespace std;
string s;
int cs[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cs[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<cs[i];j++){
			cout<<(char)(i+'0');
		}
	}
	return 0;
} 
