#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w" ,stdout);
	cin >> s1;
	for(int i=0; i<s1.size(); i++) {
		if(s1[i]>='0'&&s1[i]<='9') {
			s2 += s1[i];
		}
	}
	sort(s2.begin(), s2.end());
	reverse(s2.begin(),s2.end());
	cout << s2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
