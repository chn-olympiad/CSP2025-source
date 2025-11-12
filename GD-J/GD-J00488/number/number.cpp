#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

string s;
int f[20];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int s_len=s.length();
	for(int i=0;i<s_len;i++) {
		if(s[i]>='0' && s[i]<='9') {
			int tmp=s[i]-'0';
			f[tmp]++;
		}
	}
	for(int i=9;i>=0;i--) {
		for(int j=1;j<=f[i];j++) {
			printf("%d",i);
		}
	}
	return 0;
}

