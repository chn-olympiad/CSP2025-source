#include<bits/stdc++.h>
using namespace std;

int num[15];
char s[1000005];
bool chc(){
	for(int i = 1; i <= 9; i++) if(num[i] != 0) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	int a = 1, cnt = 0;
	while(cin >> s[a]){
		if(isdigit(s[a]) && s[a] >= 48 && s[a] <= 57) num[s[a] - '0']++;
		a++;
	}
	
	if(!chc()) return cout << 0, 0;
	for(int i = 9; i >= 0; i--)
		if(num[i] >= 1) for(int j = 1; j <= num[i]; j++) cout << i;
	
	return 0;
}