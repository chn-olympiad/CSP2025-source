#include <bits/stdc++.h>
using namespace std;
int book[1000009];
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	int cnt = 0;
//	char t;
//	while(cin >> t){
//		if(t == 'a') break;
//		if(t >= '0' && t <= '9'){
//			book[++cnt] = t - '0';
//		}
//	}
	string s;
	cin >> s;
//	cout << s;
//	return 0;
	for(int i = 0;i <= s.size();i++){
		if(s[i] == '\0') break;
		if(s[i] >= '0' && s[i] <= '9'){
			book[++cnt] = s[i] - '0';
		}
	}
	sort(book + 1 , book + 1 + cnt);
	for(int i = cnt;i >= 1;i--) printf("%d" , book[i]);
//	cout << "\n" << cnt;
	return 0;
}
