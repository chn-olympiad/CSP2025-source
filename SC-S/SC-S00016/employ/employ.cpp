#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
template <typename T> inline void read(T &x){
	x = 0;
	LL f = 1;
	char c = getchar();
	for(; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c=getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void print(T x){
	if(x < 0) x = -x,putchar('-');
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
inline void sprint(const string s){
	for(auto x : s) putchar(x);
	return;
}
const int N = 1e5 + 11;
const LL Big = 998244353;
LL n,m;
LL a[N],c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	cin>>s;
	for(LL i=1;i<=n;i++){
		read(a[i]);
		c[i] = i;
	}
	LL cnt = 0;
	do{
		LL den = 0,pss = 0;
		for(LL i=1;i<=n;i++){
			if(a[c[i]] <= den){
				den ++;
				continue;
			}
			if(s[i - 1] == '0') den ++;
			else pss ++;
		}
		if(pss >= m) cnt ++;
		cnt %= Big;
	}while(next_permutation(c + 1,c + 1 + n));
	print(cnt);
	return 0;
}
