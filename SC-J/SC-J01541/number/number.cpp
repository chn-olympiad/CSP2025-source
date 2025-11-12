#include <bits/stdc++.h>
using namespace std;
long long m4[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m4[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=m4[i];j>0;j--){
			cout << i;
		}
	}
	return 0;
}