#include<bits/stdc++.h>
using namespace std;
long long a[20];
string s;
void ss(char c) {
	if(c=='1') {
		a[1]++;
	}
	if(c=='0') {
		a[0]++;
	}
	if(c=='2') {
		a[2]++;
	}
	if(c=='3') {
		a[3]++;
	}
	if(c=='4') {
		a[4]++;
	}
	if(c=='5') {
		a[5]++;
	}
	if(c=='6') {
		a[6]++;
	}                        
	if(c=='7') {
		a[7]++;
	}
	if(c=='8') {
		a[8]++;
	}
	if(c=='9') {
		a[9]++;
	}
	return ;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0; i<s.size(); i++)ss(s[i])	;
	for(long long i=9; i>=0; i--) {
		if(a[i]==0)continue;
		for(long long j=1; j<=a[i]; j++) {
			cout<<i;
		}
	}
	return 0;
}
