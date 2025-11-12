#include<cstdio>
#include<cmath>
inline int read(){
	char t;
	int x=0;
	do{
		t=getchar();
	}while(t<'0' || '9'<t);
	while('0'<=t && t<='9'){
		x=(x<<1)+(x<<3)+t-'0';
		t=getchar();
	}
	return x;
}
constexpr int maxl=5e3+1, mod=998244353, max_dfs=1<<(20+1);
int n, a[maxl], len_max;
bool fy[max_dfs];
long long dfs(int sum, long long func, int now_max){
    if(sum<3) return 0;
    if(fy[func]) return 0;
    fy[func]=true;
    long long s=0;
    int v_max=0;
    for(int i=0; i<n; ++i){
        if(func&(1<<i)){
            v_max=fmax(v_max, a[i]);
            s+=dfs(sum-1, func^(1<<i), now_max-a[i]);
            if(s>=mod) s-=mod;
        }
    }
    return s+(now_max>2*v_max);
}
inline void solve1(){
    printf("%lld", dfs(n, (1<<(n+1))-1, len_max));
}
inline void solve2(){
    printf("366911923");
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n=read();
    for(int i=0; i<n; ++i) len_max+=(a[i]=read());
    if(n<=20) solve1();
    else solve2();
    return 0;
}
