#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 7;

string s, k;
int l = 0;
char c[N];

bool cmp(char a, char b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	int len = s.size();
	
	for(int i = 0; i < len; ++i){
		if(s[i] >= '0' && s[i] <= '9') c[l++] = s[i];
	}
	
	sort(c, c + l, cmp);
	
	for(int i = 0; i < len; ++i) cout << c[i];
	
	return 0;
}
