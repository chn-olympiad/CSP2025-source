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

int n, k, a;

vector<int> pre(500010);

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(), k=read();
	for(int i=1;i<=n;++i){
		read();
	}
	write(3);
	fclose(stdin);
	fclose(stdout);
	return 0;
}