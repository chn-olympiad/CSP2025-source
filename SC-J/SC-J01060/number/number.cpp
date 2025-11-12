#include <iostream>
using namespace std;
// 无前导零的忧虑
int P[50];
string s; 

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int cd = s.size();
	
	for (int i = 0; i < cd; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int tmp = s[i] - '0';
			P[tmp]++;
		}
	}
	
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= P[i]; j++) {
			cout << i;
		}
	}


	return 0;
}
