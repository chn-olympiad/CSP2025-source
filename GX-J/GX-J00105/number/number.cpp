#include<bits/stdc++.h>

using namespace std;

string s;
int times[100];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = int(s.size());
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int num = s[i] - '0';
			times[num]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		while(times[i]){
			printf("%d", i);
			times[i]--;
		}
	}
	return 0;
}
