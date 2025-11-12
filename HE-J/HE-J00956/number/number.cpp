#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],cnt;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='0'|| s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
			a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt; i>=1; i--)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
