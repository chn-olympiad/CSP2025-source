#include <bits/stdc++.h>
using namespace std;
int o[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if (s[i]>='0' && s[i]<='9'){
			o[s[i]-'0']++;
		}
	}
	for (int i=9;i>=1;i--){
		while (o[i]--){
			cout<<i;
		}
	}
	return 0;
}
