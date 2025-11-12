#include<cstdio>
#include<cmath>
inline long long read(){
	char t;
	long long x=0;
	do{
		t=getchar();
	}while(t<'0' || '9'<t);
	while('0'<=t && t<='9'){
		x=(x<<1)+(x<<3)+t-'0';
		t=getchar();
	}
	return x;
}
constexpr int maxl=5e5+1;
int n, dp[maxl], p, s;
long long k, a[maxl], tmp;
inline void solve1(){
    for(int i=1; i<=n; ++i){
        p=i;
        tmp=0;
        while(--p>=0) if((tmp^=a[p+1])==k) break;
        if(p>=0) dp[i]=fmax(dp[i-1], dp[p]+1);
        else dp[i]=dp[i-1];
    }
    printf("%d", dp[n]);
}
inline void solve2(){
    for(int i=1; i<=n; ++i) if(a[i]==k) ++s;
    printf("%d", s);
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n=read(); k=read();
    for(int i=1; i<=n; ++i) a[i]=read();
    if(n<=1e3) solve1();
    else solve2();
    return 0;
}
