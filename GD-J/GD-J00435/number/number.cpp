#include<bits/stdc++.h>
using namespace std;
int cnt[16];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char ch : s) {
		if(isdigit(ch))cnt[ch-48]++;
	}
	for(int i = 9; i>=0; --i)while(cnt[i]--)cout<<i;
}
