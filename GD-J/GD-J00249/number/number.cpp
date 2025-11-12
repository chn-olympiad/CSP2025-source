#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000005];
int cnt=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if(s[i]>='0'&&s[i]<='9') {
			c[++cnt]=s[i];
		}
	}
	sort(c+1,c+1+cnt);
	if(c[cnt]=='0') cout<<'0';
	else for(int i=cnt;i>=1;i--) {
		cout<<c[i];
	}
	return 0;
} 
