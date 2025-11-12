#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
#include<queue>
#include<set>
#include<unordered_map>
#include<bitset>
#include<random>
#define ci const int
#define iv inline void
#define ic inline ci
#define ll long long
#define ull unsigned ll
//#define int ll
#define gc getchar_unlocked
#define pc putchar
ic re();iv pr(ci x);iv prs(ci x);iv prn(ci x);
iv swp(int&a,int&b){a^=b^=a^=b;}
ic Max(ci a,ci b){return a>b?a:b;}
ic Min(ci a,ci b){return a<b?a:b;}
iv gma(int&a,ci b){a=Max(a,b);}
iv gmi(int&a,ci b){a=Min(a,b);}
ic Abs(ci a){return a<0?-a:a;}
int n,m;
inline const bool get01(){
	char c=gc();
	while(c!=48&&c!=49)c=gc();
	return c&1;
}
#define N 503
std::bitset<N>b;
int c[N];
int awa[11];
iv bf(){
	for(int i=1;i<=n;++i)awa[i]=i;
	int ans=0,los,val;
	do{
		los=0;val=0;
		for(int i=1;i<=n;++i)
			if(!b[i]||los>=c[awa[i]])++los;
			else++val;
		if(val>=m)++ans;
	}while(std::next_permutation(awa+1,awa+n+1));
	prn(ans);
}
int sumones;
iv work(){
	n=re(),m=re();
	for(int i=1;i<=n;++i)
		b[i]=get01(),sumones+=b[i];
	for(int i=1;i<=n;++i)
		c[i]=re();
	if(sumones<m)return prn(0);
	if(n<=10)return bf();
	prn(0);
}
/*
ulimit -s 10240
10 MB
143 min
2/25
*/
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int T=1||re();T--;)work();
}
ic re(){
	int x=0;char c=gc(),f=0;
	while(c<48||c>57)f|=(c=='-'),c=gc();
	while(c<58&&c>47)x=x*10+(c^48),c=gc();
	return f?-x:x;
}
void pri(ci x){if(x>9)pri(x/10);pc(x%10^48);}
iv pr(ci x){if(x<0)pc('-'),pri(-x);else pri(x);}
iv prs(ci x){pr(x),pc(32);}
iv prn(ci x){pr(x),pc(10);}
/*
g++ -Wall -Wextra -O2 1.cpp -o 1
Ren5Jie4Di4Ling5%
*/