#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N];
bool cmp(int a, int b){
	return a > b; 
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt = 0;
	string s;
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9') a[++cnt] = s[i] - '0'; 
	}
	sort(a + 1, a + cnt + 1, cmp); 
	for(int i = 1; i <= cnt; i++) cout << a[i]; 
	return 0;
}
