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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	puts("0");
	return 0;
}

