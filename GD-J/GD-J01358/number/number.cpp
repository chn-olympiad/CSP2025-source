#include<bits/stdc++.h>
using namespace std;
const int M = 1e6 + 1;
char a[M];
bool cmp(char a, char b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int ans = 0;
	cin >> s;
	int cnt = s.length();
	for(int i = 0; i <= cnt+1; i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[ans] = s[i];
			ans++;
		}
	}
	sort(a+0, a+ans, cmp);
	for(int i = 0; i <= ans - 1; i++) cout << a[i];
	return 0;
}
