#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n,vis[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0; i<n; i++) {
		if(s[i]>='0' and s[i]<='9') {
			vis[s[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--) {
		while(vis[i]--)cout<<i;
	}
}
