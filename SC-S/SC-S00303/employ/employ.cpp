#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long f[1000050];
int n,m,c[100050],s[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	f[0]=1;
	for(int i=1;i<=100;i++){
		f[i]=(f[i]+(f[i-1]*i)%mod)%mod;
	}
	long long ans=0;
	for(int i=m;i<=n;i++){
		ans=(f[i]+ans)%mod;
	}
	printf("%lld",ans);
}
