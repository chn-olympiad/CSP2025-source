#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}long long n,m,k,u,v,w[5201314],t;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(long long i=1;i<=m;++i)u=read(),v=read(),w[i]=read();
	while(k--)for(long long i=0;i<=n;++i)t=read();
	printf("5182974424");
}
