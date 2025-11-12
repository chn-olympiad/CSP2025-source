#include<bits/stdc++.h>
using namespace std;
char c[1000010];
long long k[9];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c;
	for(long long i = 0; i < strlen(c); i++) {
		if(c[i] >= '0' &&c[i] <= '9'){
			k[c[i] - '0']++;
		}
	}
	for(long long i = 9; i >= 0; i--) {
		for(long long j = 0; j < k[i]; j++){
			cout << i;
		}
	}
	return 0;
}