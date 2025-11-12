#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
int a[N];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			a[len] = s[i] - '0';
			len++;
		}
	}
	
	sort(a, a+len, cmp);
	for(int i = 0; i < len; i++) printf("%d", a[i]);
	return 0;
}
