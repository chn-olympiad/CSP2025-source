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

const int N=5e5+5;
var n,q,zbegin[N],zend[N];
bool now;
char s[2][N],t[2][N],input[N];

bool cmp(char x[],char y[],var r){
	static var i;
	upp(i,0,r){
		if(x[i] != y[i]) return 0;
	}
	return 1;
}
void code(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);
	read(q);
	var i,sum = 1,j,len,k,ans;
	upp(i,1,n){
		scanf("%s",input+1);
		//zbegin[i] = sum;
		//zend[i] = sum + strlen(input) - 1;
		//upp(j,zbegin[i],zend[i]){
		//	s[0][j] = input[j - zbegin[i] + 1];
		//}
		scanf("%s",input+1);
		//upp(j,zbegin[i],zend[i]){
		//	s[1][j] = input[j - zbegin[i] + 1];
		//}
		//sum += strlen(input);
	}
	upp(i,1,q){
		scanf("%s",t[0]+1);
		scanf("%s",t[1]+1);
		//len = strlen(t[0]);
		ans = 0;
		//upp(j,1,len){
		//	upp(k,1,n){
		//		if(zend[k] - zbegin[k] + 1 < j) continue;
		//		now = cmp(s[0]+zbegin[k],t[0]+zbegin[i]+j-zend[i],zend[i]-zbegin[i]) && cmp(s[1]+zbegin[k],t[1]+zbegin[i]+j-zend[i],zend[i]-zbegin[i])
		//		&& cmp(t[0]+1,t[1]+1,zbegin[i]+j-zend[i]-2) && cmp(t[0]+j+1,t[1]+j+1,len-j-1);
		//		if(now) ans++;
		//	}
		//}
		printf("%d\n",ans);
	}
}
int main(){
	code();
	return 0;
}