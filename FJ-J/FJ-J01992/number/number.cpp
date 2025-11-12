#include <bits/stdc++.h>

#define LL long long

using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	char cs[1000002] = { 0 };
	string str; cin>>str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			cs[i] = str[i];
		}
	}
	sort(cs, cs + str.size(), greater<char>());
	for (int i = 0; i < str.size(); i++) {
		cout<<cs[i];
	}
	return 0;
}

