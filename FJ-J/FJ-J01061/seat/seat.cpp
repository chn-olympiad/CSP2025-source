#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}long long n,m,a[5201314],r=1,p;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	n=read(),m=read();
	for(long long i=1;i<=n*m;++i)a[i]=read(),r+=(a[i]>a[1]);
	p=(r+n-1)/n,printf("%lld %lld",p,p&1?(!(r%n)?n:r%n):(n+1-(!(r%n)?n:r%n)));
}
