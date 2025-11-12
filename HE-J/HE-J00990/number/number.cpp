#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
	int n;
	string s;
	cin >> s;
	for(int i=0; i<=n; i++){
		if(s[i]=='0'&&s[i]=='1'){
			cout << s[i];
		}
	}
	cout << s;
	return 0;
}
