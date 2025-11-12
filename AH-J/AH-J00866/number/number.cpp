#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for (int i=0;i<l;i++) {
		if (s[i]>='0'&&s[i]<='9') n[s[i]-'0']++;
	}
	for (int i=9;i>=0;i--) {
		while (n[i]--) cout<<i;
	}
	return 0;
}
