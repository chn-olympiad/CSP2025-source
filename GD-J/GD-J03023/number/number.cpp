#include<bits/stdc++.h>
using namespace std;

string s;
int len;
int arr[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.length();
	for(int i = 0; i < len; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			int num = s[i] - '0';
			arr[num]++;
		}
	}
	
	for(int i = 9; i >= 0; i--) {
		while(arr[i] > 0) {
			cout << i;
			arr[i]--;
		}
	}
	return 0;
}
