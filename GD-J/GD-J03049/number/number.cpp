#include <bits/stdc++.h>
using namespace std;

string s;
int b[14];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		if(s[i] >= '0' && s[i] <= '9'){
			++ b[s[i] - '0'];
		}
	}
	for(int i=9; i>=0; --i){
		for(int j=b[i]; j; --j){
			cout << i;
		}
	}
	return 0;
}
