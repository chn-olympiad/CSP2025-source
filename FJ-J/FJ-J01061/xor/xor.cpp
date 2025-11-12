#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}long long n,k,a[5201314],s[5201314],f[5200][5200],d,la,re;
struct A{long long l,r;}p[5201314];
bool cmp(A a,A b){return a.l==b.l?a.r<b.r:a.l<b.l;}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(long long i=1;i<=n;++i)a[i]=read(),s[i]=s[i-1]^a[i];
	for(long long l=1;l<=n;++l)for(long long r=l;r<=n;++r)if((s[l-1]^s[r])==k)p[++d].l=l,p[d].r=r;
	sort(p+1,p+d+1,cmp),la=-1;
	for(long long i=1;i<=d;++i)if(p[i].l>la)++re,la=p[i].r;
	printf("%lld",re);
}
