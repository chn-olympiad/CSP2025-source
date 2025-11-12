#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s1[maxn];
bool cmp(char a, char b){
	return int(a) >= int(b);
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, c = 0;
	string s;
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			s1[i] = s[i];
			c++;
		}
	}
	sort(s1, s1 + n, cmp);
	for(int i = 0; i < c; i++){
		cout << s1[i];
	}
	return 0;
}