#include<bits/stdc++.h>
using namespace std;

bool cmp(char a, char b){
	return a > b;
}

string s;
int w;
char b[10000001];
int main(){
	freopen("number.out", "r", stdin);
	freopen("number.in", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			b[++w] = s[i];
		}
	}
	sort(b + 1, b + w + 1, cmp);
	for(int i = 1; i <= w; i++){
		cout << b[i];
	}
	return 0;
} 
