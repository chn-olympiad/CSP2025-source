#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
string s;
int v[N];
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	s=" "+s;
	for(int i=1; i<=len; i++) {
		if(s[i]>='0'&&s[i]<='9')v[s[i]-'0']++;
	}
	for(int i=9; i>=0; i--) {
		while(v[i]--)cout<<i;
	}
	return 0;
}
