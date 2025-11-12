#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0){
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	n=read();
	q=read();
	for(int i=1;i<=q;i++){
		putchar('0');
		putchar('\n');
	}
	return 0;
}
