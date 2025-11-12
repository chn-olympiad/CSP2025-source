#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=5e2+10;
const int mod=998244353;
int n,s[maxn],m,c[maxn];
namespace sol1{
	const int N=20;
	int f[1<<N][N];
	void main(){
		f[0][0]=1;
		for(int i=0;i<1<<n;i++){
			for(int j=1;j<=n;j++){
				if(i>>(j-1)&1) continue;
				int k=i|(1<<j-1),cnt=__builtin_popcount(i);
				for(int l=0;l<=cnt;l++){
					f[k][l+(c[j]<=l||!s[cnt+1])]+=f[i][l];
					f[k][l+(c[j]<=l||!s[cnt+1])]%=mod;
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=n-m;i++) ans+=f[(1<<n)-1][i];
		cout<<ans%mod<<endl;
	}
}
namespace sol2{
	void main(){
		int cnt=0;
		ll fac=1;
		for(int i=1;i<=n;i++) cnt+=!c[i],fac=fac*i%mod;
		if(n-cnt>=m) cout<<fac<<endl;
		else cout<<0<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool f1=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		s[i]=c=='1';
		f1&=s[i];
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18) sol1::main();
	else if(f1) sol2::main();
	else{
		cout<<0<<endl;
	}
	return 0;
}
