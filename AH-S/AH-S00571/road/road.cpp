#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,k;
int ans=0;
int read();
void write(int x);
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) {
		int u,v,w;
		u=read(),v=read(),w=read();
		ans+=w;
	}
	for(int i=1;i<=k;i++) {
		int c=0;
		for(int j=1;j<=n+1;j++)
			c=read();
	}
	write(ans);
	return 0;
}
int read() {
	int Arc=0,pre=1;
	char ch=getchar();
	while(ch<48||ch>57) {
		if(ch==45) pre=-1;
	ch=getchar(); }
	while(48<=ch&&ch<=57) {
		Arc=(Arc<<3)+(Arc<<1)+(ch^48);
	ch=getchar(); }
	return Arc*pre;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	int _stack[35],_cnt=0;
	do{
		_stack[++_cnt]=x%10,x/=10;
	}while(x);
	while(_cnt) putchar(_stack[_cnt--]^48);
	puts("");
}
