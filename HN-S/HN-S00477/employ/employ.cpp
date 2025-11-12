#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define F(i,r,l) for(int i=r;i>=l;--i)
#define int long long
#define ULL unsigned long long
#define read(n) {int _x=0,_t=1;char _c=getchar();while(!isdigit(_c)){if(_c=='-')_t=-1;_c=getchar();}while(isdigit(_c))_x=_x*10+_c-'0',_c=getchar();n=_x*_t;}
using namespace std;
const int N=505,mod=998244353;
int n,m,fac[N],c[N],p[N],ans;
char s[N];
bool solve(){
	int res=0,t=0;
	f(i,1,n){
		if(res>=c[p[i]]) ++res;
		else if(s[i]=='0') ++res;
		else ++t;
	}
	return t>=m;
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	scanf("%s",s+1);
	f(i,1,n) read(c[i]);
	fac[0]=1;
	f(i,1,n) fac[i]=fac[i-1]*i%mod;
	f(i,1,n) p[i]=i;
	if(n<=10){
		f(i,1,fac[n]){
			ans+=solve();
			next_permutation(p+1,p+n+1);
		}
		printf("%lld\n",ans);
		return 0;
	}
	printf("0\n");
	return 0;
}

