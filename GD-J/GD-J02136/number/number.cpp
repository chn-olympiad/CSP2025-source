#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,ct[10];
string s;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("A.txt","r",stdin);
//	freopen("cyq.txt","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++) {
		if(s[i]>='0'&&s[i]<='9') ct[s[i]-'0']++;
	}
	bool fl=0;
	for(int i=9;i>=1;i--) {
		for(int j=1;j<=ct[i];j++) {
			cout<<i;
			fl=1;
		}
	}
	if(fl) {
		for(int j=1;j<=ct[0];j++) cout<<0;
	} else cout<<0; 
	return 0;
}
/*
0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx


*/
