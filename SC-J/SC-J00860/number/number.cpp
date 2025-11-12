#include<bits/stdc++.h>
using namespace std;
string s, ans;
char cnt[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int ch[100];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == '0')ch[0]++;
		else if (s[i] == '1')ch[1]++;
		else if (s[i] == '2')ch[2]++;
		else if (s[i] == '3')ch[3]++;
		else if (s[i] == '4')ch[4]++;
		else if (s[i] == '5')ch[5]++;
		else if (s[i] == '6')ch[6]++;
		else if (s[i] == '7')ch[7]++;
		else if (s[i] == '8')ch[8]++;
		else if (s[i] == '9')ch[9]++;
	}
	for (int i = 9; i >= 0; i--)
		if (ch[i] != 0)
			while (ch[i]) {
				ans += cnt[i];
				ch[i]--;
			}
	cout << ans;
	return 0;
}