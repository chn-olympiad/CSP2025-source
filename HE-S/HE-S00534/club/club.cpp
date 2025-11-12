#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <typename T>
inline void read(T&x){
	int w = 0; x = 0;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') w = 1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		x = x*10+(ch^48);
		ch = getchar();
	}
	if(w) x = -x;
}
template <typename T,typename...Args>
inline void read(T&t,Args&...args){
	read(t); read(args...);
}
template <typename T>
inline T Max(T x,T y){ return (x > y ? x : y); }
template <typename T>
inline T Min(T x,T y){ return (x < y ? x : y); }
template <typename T>
inline T Abs(T x){ return (x < 0 ? -x : x); }
const int N = 1e5+10;
int n;
struct node{
	int a,b,c;
}g[N];
namespace Sub1{
int f[2][210][210];
inline void solve(int T){
	f[1][1][0] = g[1].a;
	f[1][0][1] = g[1].b;
	f[1][0][0] = g[1].c;
	int m = n/2;
	for(int i=2;i<=n;++i){
		int lim = Min(i,m);
		for(int j=0;j<=lim;++j){
			for(int k=0;k<=i-j;++k){
				f[0][j][k] = f[1][j][k];
				f[1][j][k] = 0;
			}
		}
		for(int j=0;j<=lim;++j){
			for(int k=0;k<=i-j;++k){
				int p = i-j-k;
				if(p<0 || p>m) continue;
				if(j) f[1][j][k] = Max(f[1][j][k],f[0][j-1][k]+g[i].a);
				if(k) f[1][j][k] = Max(f[1][j][k],f[0][j][k-1]+g[i].b);
				if(p) f[1][j][k] = Max(f[1][j][k],f[0][j][k]+g[i].c); 
			}
		}
	}
	int ans = 0;
	for(int j=0;j<=m;++j){
		for(int k=0;k<=m;++k){
			int p = n-j-k;
			if(p<0 || p>m) continue;
			ans = Max(ans,f[1][j][k]);
		}
	}
	printf("%d",ans);
	if(T){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=m;++k){
				f[0][j][k] = f[1][j][k] = 0;
			}
		}
	}
}
} 
int fa = 1;
namespace Sub2{
inline int cmp2(node x,node y){
	return x.a > y.a;
}
inline void solve(){
	sort(g+1,g+1+n,cmp2);
	int m = n/2;
	ll ans = 0;
	for(int i=1;i<=m;++i) ans += g[i].a;
	printf("%lld",ans);
}
}
namespace Sub3{
inline void solve(){
}
}
inline void Init(){
	
	fa = 1;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T; read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;++i){
			read(g[i].a,g[i].b,g[i].c);
			if(g[i].b || g[i].c) fa = 0;
		} 
		if(n<=200) Sub1 :: solve(T);
		else if(fa) Sub2 :: solve();
		else Sub2 :: solve();
		if(T){
			putchar('\n');
			Init();
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8 
4 0 0

1
10
10 3 2
5 6 9
3 2 1
7 2 4
1 8 2
0 3 7
2 4 5
1 6 3
2 4 9
9 2 1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107

*/
