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

const ll N=5e5+50;
ll a[N],n;

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	bool k=true;
	for(ll i=1; i<=n; ++i) {
		a[i]=read();
		if(a[i]!=1) k=false;
	}
	sort(a+1,a+1+n);
	if(n==3) {
		if(a[1]+a[2]+a[3]>a[3]*2) putchar('1');
		else putchar('0');
		return 0;
	}
	if(k){
		ll ans=1;
		for(ll i=4;i<=n;++i){
			ans=ans+i;
		}
		if(n>=3) write(ans);
		else putchar('0');
		return 0;
	}
	putchar('0');
	return 0;
}
