#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],cnt;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	s=" "+s;
	for(int i=1; i<=len; i++) {
		if(s[i]>='0' && s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt; i>=1; i--) cout<<a[i];
	return 0;
}
/*水题 （入门？）        应该人人AC*/
