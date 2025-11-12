#include <bits/stdc++.h>
using namespace std;
string s;
int c[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++){
			putchar(i+'0');
		}
	}
	return 0;
} 
