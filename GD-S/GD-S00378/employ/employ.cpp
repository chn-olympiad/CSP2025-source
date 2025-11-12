#include<bits/stdc++.h>
#define ll long long
#define sco 1010
using namespace std;
char s[sco];
ll n,m,ans,a[sco],f[sco],v[sco];
void dfs(ll k){
	if(k==n+1){
		ll res=0;
		for(int i=1;i<=n;++i){
			ll tmp=0;
			if(a[f[i]]<=tmp||s[f[i]]=='0'){
				++tmp;
			}else{
				tmp=0;
				++res;
			}
		}
		if(res>=m)++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!v[i]){
			f[i]=i;
			v[i]=1;
			dfs(k+1);
			v[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
		v[i]=f[i]=0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
