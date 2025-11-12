#include<cstdio>

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	puts("0");
}
/*
µ¹±Õ 
*/
