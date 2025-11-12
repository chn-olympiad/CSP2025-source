#include<bits/stdc++.h>
using namespace std;
int b[1000005], c;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			b[c++]=s[i]-'0';
	sort(b, b+c);
	for(int i=c-1;i>=0;i--)cout << b[i];
	return 0;
}
