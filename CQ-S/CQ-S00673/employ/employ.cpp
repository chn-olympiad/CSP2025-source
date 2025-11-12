#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,cnt,qq,c[N],bottle[N],pref[N],fact[N]={1};
long long ans;
bool vis[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i=1;i<N;i++) fact[i]=1ll*i*fact[i-1]%mod;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&vis[i]);
		cnt+=vis[i];
	}
	for(int i=1;i<=n;i++) pref[i]=bottle[i]+pref[i-1];
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		bottle[c[i]]++;
	}
	while(true){
		if(qq==pref[qq]) break;
		qq=pref[qq];
	}
	if(qq+m>n||qq+cnt<n) ans=0;
	else if(m==1)
		for(int i=1;i<=n;i++) ans=(ans+((bottle[i]*fact[pref[i-1]]%mod)*fact[pref[n]-pref[i]])%mod)%mod;
	else if(n==m) ans=(cnt==n?1:0);
	else if(cnt==n){
		for(int i=qq;i<=n;i++){
			while(true){
				if(qq==pref[qq]) break;
				qq=pref[qq];
			}
			long long mul=1;
			for(int j=n-qq;j<=n;j++) mul=(j*mul)%mod;
			ans=(ans+mul)%mod;
		}
	}else ans=0;
	printf("%lld",ans);
	return 0;
}
