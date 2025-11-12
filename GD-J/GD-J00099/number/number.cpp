#include<bits/stdc++.h>
using namespace std;
string s;
int ch[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ch[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ch[i]--){
			printf("%d",i);
		}
	}
} 
