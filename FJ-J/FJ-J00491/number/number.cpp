#include<bits/stdc++.h>
using namespace std;
string  s,ans;
long long vs[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vs[s[i]-'0']++;
		}
	}
	while(vs[9]>0){
		ans+='9';
		vs[9]--;
	}
	while(vs[8]>0){
		ans+='8';
		vs[8]--;
	}
	while(vs[7]>0){
		ans+='7';
		vs[7]--;
	}
	while(vs[6]>0){
		ans+='6';
		vs[6]--;
	}
	while(vs[5]>0){
		ans+='5';
		vs[5]--;
	}
	while(vs[4]>0){
		ans+='4';
		vs[4]--;
	}
	while(vs[3]>0){
		ans+='3';
		vs[3]--;
	}
	while(vs[2]>0){
		ans+='2';
		vs[2]--;
	}
	while(vs[1]>0){
		ans+='1';
		vs[1]--;
	}
	while(vs[0]>0){
		ans+='0';
		vs[0]--;
	}
	cout<<ans;
	return 0;
}
