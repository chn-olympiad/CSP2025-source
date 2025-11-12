#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.size()-1;
	int mx = 0;
	for(int i=0;i<=l;i++) {
		if(s[i] <= '9' && s[i] >= '0') {
			int now = s[i] - '0';
			a[now] ++;
			if(now > mx) mx = now;
		}
	}
	for(int i=9;i>=0;i--) {
		while(a[i] > 0) {
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 
