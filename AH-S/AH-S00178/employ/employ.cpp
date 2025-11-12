#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 998244353
#define N 501

using namespace std;
int n,m,c[N];
string s;
int ans;
int fac[N],p[N];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	fac[0]=1;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		fac[i]=fac[i-1]*i%mod;
	}
	if(m==n){
		int f=1;
		for(int i=1;i<=n;++i)
			if(!s[i]||!c[i]) f=0;
		cout<<f*fac[n];
	}
	else if(n<=10){
		do{
			int ban=0;
			for(int i=1;i<=n;++i)
				if(c[p[i]]>=ban||!s[i]) ++ban;
			ans=(ans+(n-ban>=m)? 1:0)%mod;
			
		}while(next_permutation(p+1,p+n+1));
		return (cout<<ans),0;
	}
	
	return 0;
}
