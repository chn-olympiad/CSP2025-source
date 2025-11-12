#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,cnt[20006];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.length();
	s = " "+s;
	for(int i = 1;i <= n; i++)	
		if(s[i] >= '0'&&s[i] <= '9') cnt[s[i]-'0']++;
	for(int i = 9;i >= 0; i--)
		for(int j = cnt[i];j >= 1; j--)
			printf("%lld",i);
	return 0;
} 
