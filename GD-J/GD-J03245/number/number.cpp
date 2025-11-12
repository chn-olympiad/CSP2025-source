#include<bits/stdc++.h>
using namespace std;
long long cnt[10]={0};;
string res="", s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin>>s;
	for (long long i=0;i<s.size();i++) {
		if (s[i] >= '0' && s[i] <='9') {
			cnt[s[i]-'0']++;
		}
	}
	
	for (int i=9;i>=0;i--) {
		for (long long j=0;j<cnt[i];j++) {
			cout<<i;
		} 
	}
	
	return 0;
}
