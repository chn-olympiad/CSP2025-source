#include<bits/stdc++.h>
using namespace std;
string s;
int b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(b[i]>0){
			for(int j=1;j<=b[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 