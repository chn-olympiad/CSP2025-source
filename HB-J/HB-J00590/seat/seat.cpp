#include<cstdio>
#include<cmath>
inline int read(){
	char t;
	int x=0;
	do{
		t=getchar();
	}while(t<'0' || '9'<t);
	while('0'<=t && t<='9'){
		x=(x<<1)+(x<<3)+t-'0';
		t=getchar();
	}
	return x;
}
constexpr int maxl=1e2+1;
int n, m, p, x=1, c, r;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n=read(); m=read();
	p=read();
	for(int i=2; i<=n*m; ++i) if(read()>p) ++x;
	c=ceil(1.0*x/n);
	r=(x%n)? (x%n):n;
	printf("%d %d", c, (c&1)? r:(n+1-r));
	return 0;
}
