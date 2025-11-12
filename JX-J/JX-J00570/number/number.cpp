#include<bits/stdc++.h>
using namespace std;
int ton[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			ton[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ton[i]){
			cout<<i;
			ton[i]--;
		}
	}
	return 0;
}
