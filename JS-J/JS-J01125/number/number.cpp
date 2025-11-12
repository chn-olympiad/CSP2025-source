#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b) {
	return b < a;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[1000005],idx = 0;
	for (unsigned int  i = 0;i < s.size();i++) 
		if (s[i] >= '0' && s[i] <= '9') a[idx++] = s[i] - '0';
	sort(a,a + idx,cmp);
	for (int i = 0;i < idx;i++) cout << a[i];
	cout << endl;
	return 0;
}
