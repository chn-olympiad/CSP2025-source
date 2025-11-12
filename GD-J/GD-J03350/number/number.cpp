#include<bits/stdc++.h>
using namespace std;
char s[1000100];
int t[1000100];
int cnt;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for(int i=0; i<l; i++) {
		if('0'<=s[i]&&s[i]<='9') {
			t[++cnt]=s[i]-'0';
		}
	}
	sort(t+1,t+cnt+1,cmp);
	for(int i=1; i<=cnt; i++) {
		cout<<t[i];
	}
	return 0;
}
