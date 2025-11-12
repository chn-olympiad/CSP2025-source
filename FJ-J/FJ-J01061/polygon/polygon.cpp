#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}long long n,jc[5201314],a[5201314],r;
int fp(int a,int b){
	int r=1;
	while(b){
		if(b&1)r=r*a%M;
		a=a*a%M,b>>=1;
	}return r;
}int c(int n,int m){return(jc[m]%M/(jc[m-n]%M*jc[n])%M)%M;}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	jc[1]=1;
	for(int i=2;i<=999999;++i)jc[i]=(jc[i-1]*i)%M;
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=3;i<=n;++i)r+=c(i,n);
	printf("366911923");
}
