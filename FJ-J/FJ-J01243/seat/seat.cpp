#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110],h,l=1,k,t=1;
inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(ll x,ll y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1; i<=n*m; i++) a[i]=read();
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1; i<=n*m; i++) {
		h+=t;
		if(h<=0||h>n) {
			h-=t;
			l++;
			t=-t;
		}
		if(a[i]==k) {
			printf("%lld %lld",l,h);
			return 0;
		}
	}
}
