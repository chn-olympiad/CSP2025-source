#include<bits/stdc++.h>
#define MAXN 5010
#define MOD 988244353
using namespace std;
typedef long long ll;
int n,m,a[MAXN],c[MAXN];
namespace Sub1{
int ord[MAXN];
	ll res=0;
	bool vis[MAXN];
	inline void dfs(int dep){
		if(dep==n+1){
			int sum=0;
			for(int i=1;i<=n;++i){
				if(c[ord[i]]<=sum||!a[i]){
					++sum;
				}
			}
			if(sum+m<=n){
				(++res)%=MOD;
			}
			return;
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				ord[dep]=i;
				vis[i]=true;
				dfs(dep+1);
				vis[i]=false;
			}
		} 
	}
	inline void Main(){
		dfs(1);
		printf("%lld",res);
	} 
}
namespace Sub2{
	inline void Main(){
		int sum=0;
		ll res=1;
		for(int i=1;i<=n;++i){
			sum+=c[i]&&a[i];
			(res*=i)%=MOD;
		}
		printf("%d",(sum^n^1)*res);
	}
}
namespace Sub3{
	inline ll power(ll a,ll b){
		ll res=1;
		while(b){
			if(b&1){
				(res*=a)%=MOD;
			}
			(a*=a)%=MOD;
			b>>=1;
		}
		return res;
	}
	inline void Main(){
		if(m>1){
			puts("0");
			return;
		} 
		int sum=0,ind;
		ll res=1;
		for(int i=1;i<=n;++i){
			if(a[i]){
				ind=i;
			}
		}
		for(int i=1;i<=n;++i){
			if(c[i]>=ind){
				++sum;
			}
			if(i^n){
				(res*=i)%=MOD;
			}
		} 
		printf("%lld",sum*res%MOD);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;++i){
		scanf("%1d",&a[i]);
		sum+=a[i];
	} 
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	} 
	if(sum<m){
		puts("0");
		return 0;
	}
	if(n<=18){
		Sub1::Main();
		return 0;
	}
	if(m==n){
		Sub2::Main();
		return 0;
	}
	if(m==1){
		Sub3::Main();
		return 0;
	}
	Sub1::Main();
	return 0;
}
