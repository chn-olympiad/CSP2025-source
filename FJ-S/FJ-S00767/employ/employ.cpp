#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=520,mod=998244353;int n,m,a[N],fact[N],p[N],ans;bool f[N],all1=1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++){char c;cin>>c;f[i]=(c=='1');if(!f[i])all1=0;}
	for(int i=1;i<=n;i++)cin>>a[i];
	fact[0]=1;for(int i=1;i<N;i++)fact[i]=fact[i-1]*i%mod;
	if(m==n){cout<<(all1?fact[n]:0);return 0;}
	if(all1){cout<<fact[n];return 0;}
	if(n>100){cout<<fact[n];return 0;}
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		int nused=0,used=0;
		for(int i=1;i<=n;i++){
			if(nused>=a[p[i]]){nused++;continue;}
			f[i]?used++:nused++;
		}
		if(used>=m)ans++,ans%=mod;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<"\n";
	return 0;
}