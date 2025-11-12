#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0; i<s.size(); i++){
		if(isdigit(s[i])){
			cnt[s[i] - '0']++;
		}
	}
	for(int i=9; i>=0; i--){
		for(int j=1; j<=cnt[i]; j++){
			cout << i;
		}
	}
	return 0;
}
