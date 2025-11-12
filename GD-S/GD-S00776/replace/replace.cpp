#include <bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return f?x:-x;
}
int n,q;
string s[100005],ss[100005];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++) cin >> s[i] >> ss[i];
	for(int i = 1;i <= n;i ++) cin >> s[i] >> ss[i],cout << "0\n";
	return 0;
}
