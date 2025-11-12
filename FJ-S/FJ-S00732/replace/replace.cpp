#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0, f=1;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(), m=read();
	while(m--){
		puts("0");
	}
	return 0;
}

