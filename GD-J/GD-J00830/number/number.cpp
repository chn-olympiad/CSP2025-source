#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N], len = 0;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	s = " " + s;
	int n = s.size();
	for(int i = 1; i <= n; i++){
		int x = s[i] - '0';
		if(x >= 0 && x <= 9) a[++len] = x;
	}
	sort(a + 1, a + 1 + len, cmp);
	for(int i = 1; i <= len; i++){
		cout << a[i];
	}
	return 0;
}
