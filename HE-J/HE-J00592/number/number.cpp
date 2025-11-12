#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int ans[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	cin >> s;
	if(s.length() == 1 && (s[0] <= '9' && s[0] >= '0')) cout << s[0] << endl;
	else{
		int len = 0;
		for(int i = 0;i < s.length();i++)
			if(s[i] <= '9' && s[i] >= '0') ans[++len] = s[i] - '0';
		sort(ans + 1, ans + len + 1);
		reverse(ans + 1, ans + len + 1);
		for(int i = 1;i <= len;i++) cout << ans[i];
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
