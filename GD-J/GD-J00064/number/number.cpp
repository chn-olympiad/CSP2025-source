#include <bits/stdc++.h>
using namespace std;
string s;
string ss[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0 ; i < s.size(); i++){
		if('0'<=s[i]&&s[i]<='9'){
			ss[s[i]-'0']+=s[i];
		}
	}
	for(int i = 9 ; i >= 0 ; i--){
		cout << ss[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
