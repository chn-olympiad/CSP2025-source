#include<bits/stdc++.h>
using namespace std;
#define def(X) constexpr int X=
#define LF putchar('\n')
#define SP putchar(' ')
#define int long long
template<typename T>
inline void read(T& x){
	x=0;int f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=~f+1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x*=f;
}
template<typename T,typename... Args>
inline void read(T& x,Args&... args){
	read(x);
	read(args...);
}
template<typename T>
inline void write(T x){
	static int buf[40],top=0;
	if(x<0){x=-x;putchar('-');}
	while(x){buf[++top]=x%10,x/=10;}
	if(!top)buf[++top]=0;
	while(top)putchar(buf[top--]^48);
}
template<typename T,typename... Args>
inline void write(T x,Args... args){
	write(x);
	SP;
	write(args...);
}
signed main(){
	int i,j;
	
	return 0;
}
