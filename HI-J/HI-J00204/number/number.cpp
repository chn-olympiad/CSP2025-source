#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	if(s.size() == 1){
		cout << s;
		return 0;
	}
	int n[15] = {0},cnt = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			n[s[i] - 48]++;
			cnt++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(n[i] > 0){
			cout << i;
			n[i]--;
		}
	}
	return 0;
}
