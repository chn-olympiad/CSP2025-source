#include <bits/stdc++.h>
//#define int long long
using namespace std;

string s = "";

int cnt[15];

signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(cnt,0,sizeof(cnt));
	int n = s.size();
	
	for(int i = 0;i < n;i++) {
		if(isdigit(s[i])) {
			cnt[s[i]-'0']++;
		}
	}
	
	for(int i= 9;i >= 0;i--) {
		while(cnt[i]--) cout<<i;
	}
	return 0;
}