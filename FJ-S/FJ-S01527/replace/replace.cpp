#include<bits/stdc++.h>
#define gc() getchar()
#define r(x) (x)=read()
using namespace std;
inline int read(){
	int x=0,f=1;char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=gc();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,q;
inline void solve(){
	r(n),r(q);
	while(q--){
		putchar('0');
		putchar('\n');
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;
	//r(t);
	while(t--)solve();
	return 0;
}

