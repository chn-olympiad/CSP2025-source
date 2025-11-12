#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ji = 1, cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i <= s.size();i++){
		if (s[i] == '0'){
			a[ji] = 0;
			ji ++;
		}else if (s[i] == '1'){
			a[ji] = 1;
			ji ++;
		}else if (s[i] == '2'){
			a[ji] = 2;
			ji ++;
		}else if (s[i] == '3'){
			a[ji] = 3;
			ji ++;
		}else if (s[i] == '4'){
			a[ji] = 4;
			ji ++;
		}else if (s[i] == '5'){
			a[ji] = 5;
			ji ++;
		}else if (s[i] == '6'){
			a[ji] = 6;
			ji ++;
		}else if (s[i] == '7'){
			a[ji] = 7;
			ji ++;
		}else if (s[i] == '8'){
			a[ji] = 8;
			ji ++;
		}else if(s[i] == '9'){
			a[ji] = 9;
			ji ++;
		}
	}
	sort(a + 1, a + ji);
	if (a[ji - 1] == 0){
		cout << 0;
	}else {
		for (int i = ji - 1; i >= 1; i--){
			cout << a[i];
		}
	}
	return 0;
}
