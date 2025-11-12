#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 510;
int s[N],c[N];
long long ans = 0;
int n,m;
namespace st1{
	int b[15];
	void solve(){
		for(int i = 1;i<=11;++i){
			b[i] = i;
		}
		do{
			int cnt = 0;
			for(int i = 1;i<=n;++i){
				if(cnt>=c[b[i]]||s[i]==0){
					++cnt;
				}
			}
			if(n-cnt>=m)++ans;
		}while(next_permutation(b+1,b+n+1));
	}
}
namespace st2{
	void solve(){
		ans = 1;
		for(int i = 1;i<=n;++i){
			ans*=i;
			ans%=mod;
		}
		for(int i = 1;i<=n;++i){
			if(s[i]==0||c[i]==0){
				ans=0;
				break;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		char a;
		cin>>a;
		s[i] = a-'0';
		//scanf("%d",&s[i]);
	}
	for(int i = 1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	if(n<=10){
		st1::solve();
	}else{
		st2::solve();
	}
	printf("%lld",ans%mod);
	return 0;
}
