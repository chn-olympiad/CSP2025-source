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
#define N 11
//#define NoFreopen
int a[N*N],R,n,m;
signed main(){
	#ifndef NoFreopen
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	#endif
	read(n,m);
	for(int i=1;i<=n*m;++i) read(a[i]);
	R=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int curn=1,curm=1;
	for(int i=1;i<=n*m;++i){
		if(a[i]==R) return write(curm,' ',curn),0;
		if(curm&1){
			if(curn==n) ++curm;
			else ++curn;
		}
		else{
			if(curn==1) ++curm;
			else --curn;
		}
	}
	return 0;
}
