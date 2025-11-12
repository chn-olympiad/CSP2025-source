#include<bits/stdc++.h>
using namespace std;
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
inline int read(){return 0;}
template<typename A,typename ...B>
int read(A &x,B&...y){
	x=0;int f=1,c=gc();
	for(;!isdigit(c);c=gc()){
		if(!(~c)) return 0;
		if(c=='-') f=-1;
	}
	for(;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^48);
	return x*=f,read(y...)+1;
}
inline int write(){return 0;}
inline void Write(char c){pc(c);}
inline void Write(const char *a){
	for(int i=0;a[i];++i) pc(a[i]);
}
template<typename T>
void Write(T x){
	if(x<0) pc('-'),x=-x;
	if(x<10) return pc(x^48),void(0);
	Write(x/10),pc((x%10)^48);
}
template<typename A,typename ...B>
int write(A x,B...y){
	Write(x);
	return write(y...)+1;
}
#define int long long
#define N 500010
//#define NoFreopen
int n,k,a[N],f[N],ans;
#define query(l,r) (f[r]^f[(l)-1])
#ifdef __unix
#define MAX_CLOCK 900000
#else
#define MAX_CLOCK 900
#endif
signed main(){
	#ifndef NoFreopen
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	#endif
	read(n,k);
	for(int i=1;i<=n;++i) read(a[i]),f[i]=f[i-1]^a[i];
	int last=0;
	for(int i=1;i<=n;++i){
		for(int j=last+1;j<=i;++j){
			if(query(j,i)==k){
				last=i;
				++ans;
				break;
			}
		}
		if(clock()>MAX_CLOCK) return write(ans),0;
	}
	write(ans);
	return 0;
}
