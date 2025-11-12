#include<bits/stdc++.h>
using namespace std;
bool cmp(char a, char b) {
	return a > b;
}
int main () {
	freopen("number.in","r", stdin);
	freopen("number.out","w", stdout);
	string sa, sb = "";
	cin >> sa;
	for (int i = 0; i < sa.size(); i++)
	if(sa[i] >= '0' && sa[i] <= '9') sb += sa[i];
	sort(sb.begin(), sb.end(), cmp);
	cout << sb;
	return 0;
}
