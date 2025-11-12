#include<bits/stdc++.h>
using namespace std;
string s;
int a[13];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[int(s[i]) - 48]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++){
			printf("%d", i);
		}
	}
	return 0;
}
