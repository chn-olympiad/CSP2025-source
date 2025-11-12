#include<bits/stdc++.h>
using namespace std;
#define N 505
#define int long long
int mod=998244353;
int n,m;
string s;
int num[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	int tot=n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	int ans=1;
	for(int i=1;i<=tot;i++){
		ans=(ans*i%mod+mod)%mod;
		//cout<<ans<<endl;
	}
	printf("%lld",(ans%mod+mod)%mod);
	
	return 0;
}
