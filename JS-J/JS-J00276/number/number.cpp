#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int cnt = 0;
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			num[cnt] = (int)(s[i] - '0');
		}
	}
	sort(num + 1, num + 1 + cnt);
	for(int i = cnt; i >= 1; i--){
		cout << num[i];
	}
	return 0;
}
