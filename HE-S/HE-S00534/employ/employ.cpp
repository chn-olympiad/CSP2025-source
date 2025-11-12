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
const int N = 510;
const ll mod = 998244353;
char s[N];
int n,m;
int c[N];
namespace Sub1{
int a[N];
inline void solve(){
	for(int i=1;i<=n;++i){
		a[i] = i;
	}
	ll ans = 0;
	do{
//		for(int i=1;i<=n;++i) cout << a[i] <<""; cout << endl;
		int num = 0,res = 0;
		for(int i=1;i<=n;++i){
			if(num>=c[a[i]]){
				++num;
				continue;
			}
			if(s[i]^48){
				++res;
				if(res>=m) break;
			}
			else ++num;
		}
		if(res>=m) ++ans;
		if(ans>=mod) ans -= mod;
	}while(next_permutation(a+1,a+1+n));
	printf("%lld",ans);
}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	read(n,m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		read(c[i]);
	}
//	if(n<=10){
		Sub1 :: solve();
		return 0;
//	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
3 2
101
1 1 2
*/
