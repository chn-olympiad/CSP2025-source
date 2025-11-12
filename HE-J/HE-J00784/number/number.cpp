#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read() {
	ll x=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*k;
}

inline void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}

ll shu[10];
string s,ans="";

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.length();
	for(ll i=0; i<len; ++i)
		if(s[i]>='0'&&s[i]<='9') {
			shu[s[i]-'0']++;
		}
	
	for(ll i=9; i>=0; --i) {
		while(shu[i]--) putchar(i+'0');
	}
	return 0;
}
