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

const ll N=15;
ll n,m;
ll a[N][N],s[N*N];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	ll ss=n*m;
	ll ans=s[1]=read(),xiao=1;
	for(ll i=2; i<=ss; ++i) {
		s[i]=read();
		if(s[i]>s[1]) xiao++;
	}
	ll ansj=ceil(xiao*1.0/n),ansi;
	if(ansj%2==0) {
		ansi=n-xiao%n+1;
		if(ansi>n) ansi%=n;
	} 
	else ansi=xiao-n*(ansj-1);
	write(ansj),putchar(' '),write(ansi);
	return 0;
}
