#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
typedef long long ll;
inline int read(){
	int res=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch))
		flag=(ch=='-')?-1:1,
		ch=getchar();
	while(isdigit(ch))
		res=(res<<3)+(res<<1)+(ch^48),
		ch=getchar();
	return res*flag;
}
int n,m;
ll ans=1;
void func(int x){
	ll y=ans,ret=0;
	while(x){
		if(x&1) ret=(ret+y)%MOD;
		y=(y*2)%MOD;
		x>>=1;
	}
	ans=ret;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	if(m<n) return printf("0"),0;
	for(int i=1;i<=n;i++)
		func(i);
	printf("%lld",ans);
	return 0;
}
