#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
char s[10000010];
int a[15];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    int now = 0;
	int i = 0;
    while(cin >> s[now]){
    	now++;
		if (s[i] >= '0' && s[i] <= '9'){
			a[s[i] - '0']++;
		}
		i++;
	}
	for (int j = 9; j >= 0; j--){
		while(a[j] > 0){
			cout << j;
			a[j]--;
		}
	}
	return 0;
}
