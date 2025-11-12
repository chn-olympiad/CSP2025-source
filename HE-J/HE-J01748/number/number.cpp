#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s , a = "";
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a += s[i];
		}
	}
	sort(a.begin() , a.end());
	reverse(a.begin() , a.end());
	cout << a;
	return 0;
}
