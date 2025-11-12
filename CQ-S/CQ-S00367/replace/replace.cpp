// wo zhen de bu hui zi fu chuan
#include <cstdio>
int Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
void w(T x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return 0;
}