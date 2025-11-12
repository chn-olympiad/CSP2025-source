//GZ-S00058  遵义市第四中学 刘林志远 
#include <cstdio>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

typedef long long ll;

ll fr() {
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

const int maxn=550;
const int M=998244353;

int n,m;
std::string s;
int c[maxn];

ll fac[maxn];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=fr(),m=fr();
	std::cin>>s;
	bool flag=1;
	for(int i = 1; i <= n; i++) c[i]=fr();
	for(int i = 1; i <= n; i++) flag=s[i-1]^48;
	fac[0]=1;
	for(int i = 1; i <= n; i++) fac[i]=fac[i-1]*i%M;
	if(m==n) {
		bool f=1;
		for(int i = 1; i <= n; i++) f=c[i]>0;
		printf("%lld\n",f&&flag?fac[n]:0);
	}
	else {
		int ans=0;
		int p[maxn];
		for(int i = 1; i <= n; i++) p[i]=i;
		int cnt=0;
		for(int i = 1; i <= n; i++) {
			if(!(s[i-1]^48)||cnt>=c[p[i]]) cnt++;
		}
		ans+=n-cnt>=m;
		while(std::next_permutation(p+1,p+1+n)) {
			int cnt=0;
			for(int i = 1; i <= n; i++) {
				if(!(s[i-1]^48)||cnt>=c[p[i]]) cnt++;
			}
			ans+=n-cnt>=m;
		}
		printf("%d\n",ans);
	}
	return 0;
}

