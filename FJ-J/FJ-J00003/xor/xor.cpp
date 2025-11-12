#include<bits/stdc++.h>
using namespace std;
#define f(a,b) (a) xor (b)
int read(){
	int x;bool f=0;char ch;
	while((ch=getchar())<'0' || ch>'9')if(ch=='-')f=1;
	x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
const int maxn=5e5+5;
int k,n;
int qzxor[maxn],a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		qzxor[i]=f(a[i],qzxor[i-1]);
	}
	
	return 0;
}
