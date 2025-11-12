#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.length(); i++) {
		if('0'<=s[i]&&s[i]<='9') {
			int u=s[i]-'0';
			a[u]++;
		}
	}
	for(int i=9; i>=0; i--) {
		while(a[i]>0) {
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
//define int long long
/*
ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//system("fc number.out number3.ans");
rp++;rp++;rp++;rp++;rp++;rp++;
*/
