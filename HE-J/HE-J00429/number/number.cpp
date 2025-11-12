#include<bits/stdc++.h>
using namespace std;
#define int long long
int cmp(int x,int y) {
	return x>y;
}
const int MAXN=1e6+10;
string s;
int a[MAXN];
int h;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[++h]=s[i]-'0';
		}
	}
	sort(a+1,a+h+1,cmp);
	for(int i=1; i<=h; i++) {
		cout<<a[i];
	}
	return 0;
}
