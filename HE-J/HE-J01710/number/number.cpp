#include <bits/stdc++.h>
using namespace std;
bool cmd(int x,int y) {
	return x > y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	int a[str.size()] = {-1},len = 0;
	for (int i = 0;i < str.size();i ++) {
		if (str[i] == '1') {
			a[i] = 1;
			len ++;
		}
		else if (str[i] == '2') {
			a[i] = 2;
			len ++;
		}
		else if (str[i] == '3') {
			a[i] = 3;
			len ++;
		}
		else if (str[i] == '4') {
			a[i] = 4;
			len ++;
		}
		else if (str[i] == '5') {
			a[i] = 5;
			len ++;
		}
		else if (str[i] == '6') {
			a[i] = 6;
			len ++;
		}
		else if (str[i] == '7') {
			a[i] = 7;
			len ++;
		}
		else if (str[i] == '8') {
			a[i] = 8;
			len ++;
		}
		else if (str[i] == '9') {
			a[i] = 9;
			len ++;
		}
		else if (str[i] == '0') {
			a[i] = 0;
			len ++;
		}
	}
	sort (a,a + str.size(),cmd);
	for (int i = 0;i < len;i ++) {
		if (a[i] != -1) cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
