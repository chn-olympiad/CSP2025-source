#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000006],len=0,c=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]<='9' && s[i]>='0') {
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	if(a[c-1]==0) return 0;
	for(int i=c-1; i>=0; i--) {
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;

}
