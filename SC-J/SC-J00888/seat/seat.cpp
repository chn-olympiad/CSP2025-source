#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;

inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

inline void write(int x){
	if(x<0){
		putchar('-');
		write(-x); 
		return;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

int n, m, r, ans=1;

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(), m=read(), r=read();
	for(int i=2;i<=n*m;++i){
		if(read()>r) ++ans;
	}
	write(ans/n+(ans%n!=0));
	putchar(' ');
	if((ans/n+(ans%n!=0))%2) write(ans%n+(ans%n==0)*n);
	else write(n-ans%n+(ans%n==0)*n+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}