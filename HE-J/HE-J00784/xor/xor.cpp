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
ll n,k,aaa;
ll a[N];
bool kk[N];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	ll ans=0;
	a[1]=read();
	kk[1]=true;
	ll c=1;
	for(ll i=1; i<=n; ++i) {
		if(i!=1) a[i]=read();
		ans^=a[i];
		if(ans==k) {
			kk[i]=true;
			kk[i+1]=true;
			c=i+1;
			ans=0;
			aaa++;
		}
	}
	bool kkk=false;
	if(kk[n]==false) {
		kk[c]=false;
		kkk=true;
	}
	ans=0;
	for(ll i=n; i>=1; --i) {
		if(kk[i]) {
			ans=0;
			kkk=false;
			continue;
		}
		ans^=a[i];
		if(ans==k) {
			ans=0;
			if(kkk) aaa++;
			kkk=true;
		}
	}
	cout<<aaa;
	return 0;
}
