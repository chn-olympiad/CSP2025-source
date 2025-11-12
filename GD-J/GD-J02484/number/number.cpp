#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string str;
int cnt[10];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> str;
	for(int i = 0; i < str.length(); i++){
		if('0' <= str[i] && str[i] <= '9')
			cnt[str[i]-'0']++;
	} 
	for(int i = 9; i >= 0; i--){
		while(cnt[i]--) cout << i;
	}
	return 0;
}
