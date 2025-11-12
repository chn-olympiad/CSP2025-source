#include <bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int cnt[10];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++) {
		if(s[i]>='0' && s[i]<='9') cnt[s[i]-'0']++;
	}
	int ans=-1,n=9;
	while(n>=0){
		if(cnt[n]==0) n--;
		else {
			if(ans==-1) {
				ans=n;
				cnt[n]--;
			}else {
				ans*=10;
				ans+=n;
				cnt[n]--;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
