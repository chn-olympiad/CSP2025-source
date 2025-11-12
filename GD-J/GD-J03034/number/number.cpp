#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int num[maxn];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int i = 0, c = 0;
	while(i < s.size()){
		
		if(s[i] <= '9' && s[i] >= '0'){
			num[c++] = s[i] - '0';
		}
		i++;
	} 
	sort(num, num + c);
	while(c--){
		cout << num[c];
	}
	return 0;
} 
