#include <iostream>
using namespace std;
int nums[10];
char c;
bool flag = 0;
int main() {
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	while(cin >> c) {
		if('0' <= c <= '9') {
			++nums[c - '0'];
			if (c >= '1') flag = 1;
		}
	}
	if(flag) {
		for(int i = 9;i >= 0;--i) {
			for(int j = 0;j < nums[i];++j) {
				cout << i;
			}
		}
	} else {
		cout << 0;
	}
	return 0;
}

