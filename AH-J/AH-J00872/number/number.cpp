#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t[15] = {0};
	string s;
	cin>>s;
	int l = s.length();
	for (int i = 0;i<l;i++)
		if (s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	for (int i = 9;i>=0;i--)
		for (int j = 1;j<=t[i];j++)
			cout<<i;
	return 0;
}
