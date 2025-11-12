#include <bits/stdc++.h>
#define debug(x) printf("In Function %s,Line %d,%s:%d.\n",__FUNCTION__,__LINE__,#x,x)
#define cputime printf("CPU used time:%.3lf.\n",(double) clock() / CLOCKS_PER_SEC)
#define upp(a,b,c) for(a=(b);a<=(c);a++)
#define low(a,b,c) for(a=(b);a>=(c);a++)
using namespace std;
typedef int var;

template <typename T> inline void read(T &x){
	static char ch;
	static int y;
	x = 0;
	y = 1;
	ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			y = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x * 10) + (ch - '0');
		ch = getchar();
	}
	x *= y;
}

const int N=1e5+5,mod=998244353;
var n,m,a[N],b[N],c[N],kind=1,ans;
char s[N];

void code(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	var i,j,f;
	read(n);
	read(m);
	scanf("%s",s+1);
	upp(i,1,n){
		read(b[i]);
		a[i] = i;
	}
	upp(i,2,n){
		kind *= i;
	}
	upp(i,1,kind){
		upp(j,1,n){
			c[i] = b[a[i]];
		}
		f = 0;
		upp(j,1,n){
			if(s[j] == '0' || f >= c[i]){
				f++;
			}
		}
		if(n - f >= m){
			ans++;
			ans %= mod;
		} 
		if(i != n) next_permutation(a+1,a+n+1);
	}
	printf("%d\n",ans);
}
int main(){
	code();
	return 0;
}