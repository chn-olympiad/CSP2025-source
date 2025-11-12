#include <bits/stdc++.h>
using namespace std;
int ans[1000000];
int main() {
	freopen("number.in","r",stdin);//a=97,z=122,0=48,1=49,9=57
	freopen("number.out","w",stdout);
	int la=0;
	string s;

	cin>>s;
	for(int i=0; i<=sizeof(s)+1; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			ans[la]=s[i]-48;
			la++;
		}
	}
	sort(ans,ans+la);
	for(int i=la-1; i>=0; i--) {
		cout<<ans[i];
	}
	return 0;
}
