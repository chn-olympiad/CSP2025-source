#include <bits/stdc++.h>
using namespace std;
int flag[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len_s = s.size();
	for (int i = 0; i < (int)len_s; ++i){
		if (s[i] >= '0' && s[i] <= '9'){
			++flag[s[i] - '0'];
		}
	}
	for (int i = 9; i >= 0; --i){
		if (flag[i]){
			for (int j = 1; j <= flag[i]; ++j){
				putchar((char)i + '0');
			}
		}
	}
	return 0;
}
