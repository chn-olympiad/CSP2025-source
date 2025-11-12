#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;
string s,ans;
int cnt[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	for(rint i=0;s[i];++i)
		if(isdigit(s[i]))
			++cnt[s[i]-'0'];
	for(rint i=9;i>=0;--i)
		for(rint j=1;j<=cnt[i];++j) ans+=i+'0';
	cout<<ans;
	return 0;
}
