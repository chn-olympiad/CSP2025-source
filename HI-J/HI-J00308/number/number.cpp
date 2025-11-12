#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;

int n, u[200];
char s[N];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	scanf("%s",s+1);
	n=strlen(s+1);
	
	for(char r='0';r<='9';r++)u[r]=0;
	for(int i=1;i<=n;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			u[s[i]]++;
		}
	}
	for(char r='9';r>='0';r--) {
		int t=u[r];
		while(t--) {
			putchar(r);
		}
	}
	return 0;
}
