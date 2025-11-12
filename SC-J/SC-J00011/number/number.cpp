#include<bits/stdc++.h>
using namespace std;
int m,b[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
		if((s[i]-'0')>=0&&(s[i]-'0')<=9)    m++,b[m]=s[i]-48;
	sort(b+1,b+m+1);
	for(int i=m;i>=1;i--)    cout << b[i];
	return 0;
}

