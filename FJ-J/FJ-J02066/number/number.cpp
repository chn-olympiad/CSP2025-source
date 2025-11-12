#include <bits/stdc++.h>
using namespace std;

char s[1000005] = {};

int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	sort(s,s + strlen(s));
	char num[1000005] = {};
	int cnt = 0;
	for(int i = 0;i < strlen(s);i++){
		if(!(s[i] >= '0' && s[i] <= '9')){
			continue;
		}
		num[cnt++] = s[i];
	}
	sort(num,num + cnt,greater<char>());
	cout << num;
	return 0;
}
