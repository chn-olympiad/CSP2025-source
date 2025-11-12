#include<bits/stdc++.h>
#define int long long 
#define fast register int
using namespace std;
const int maxn=1e5+5;

int n,m,a[maxn],R,x,y,now=1;

bool cmp(int x,int y){
	return x>y;
}

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(fast i=1;i<=n*m;i++){
		a[i]=read();
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	x=1,y=1;
	for(fast i=1;i<=n*m;i++){
		if(R==a[i]) break;
		if(i%n==0) y++,now*=-1;
		else x+=now;
	}
	write(y);
	putchar(' ');
	write(x);
	return 0;
}