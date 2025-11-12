#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000005],cnt;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++) {
		if(s[i]>='0' && s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
} 
