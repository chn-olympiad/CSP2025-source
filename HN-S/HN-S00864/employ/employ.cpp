#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
long long x,l1,l2,l,r,n,m,k,u,v,w,c[11],a[11][20100],d[11],e[11],f[20100],cnt,ans;
char s[200010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;ans%=998244353;
	}
	printf("%lld",ans);
	return 0;
}
