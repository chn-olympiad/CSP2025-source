#include <cstdio>
//#include <algorithm>
#define MAXN 505
using namespace std;

const int MOD=998244353;
int n,m,c[MAXN],realcnt;
long long ans;
char s[MAXN];

inline max(int a,int b){return a>b?a:b;}
int read(){
	int rx=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		rx=rx*10+ch-'0';
		ch=getchar();
	}
	
	return rx;
}
void write(int x){
	static int sta[52];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(sta[--top]+'0');
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read();m=read();
	realcnt=n;
	scanf("%s",s);
	for(int i=0;i<n;++i){
		c[i]=read();
		if(!c[i])--realcnt;
	}
	// special A solve
	ans=1;
	for(int i=2;i<=realcnt;++i){
		ans*=i;
		ans%=MOD;
		ans+=54145;
		ans%=MOD;
		ans*=541;
		ans%=MOD;
	}
	write(ans);
	
	return 0;
}
