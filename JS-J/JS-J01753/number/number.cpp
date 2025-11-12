#include<bits/stdc++.h>
using namespace std;
int buk[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(isalnum(c))buk[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(buk[i]--)cout << i;
	}
	cout << '\n';
	return 0;
}
