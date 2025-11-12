#include <iostream>
using namespace std;

int n[10];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for(char c : s){
		if(c >= '0' && c <= '9')
			n[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(n[i]--) cout << i;
	}
	return 0;
}