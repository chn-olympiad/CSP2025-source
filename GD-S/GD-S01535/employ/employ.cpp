#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mo=998244353;
const int N=1<<19;
int m;
int n,popc[N],s[N],c[N];
ll f[N][20];
char ch;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	if(n<=18) {
		f[0][0]=1;
		for(int S=0; S<(1<<n); S++) {
			if(S) popc[S]=popc[S>>1]+(S&1);
			for(int k=0; k<=n; k++) {
				if(!f[S][k]) continue;
				for(int i=1; i<=n; i++) {
					if(S&(1<<(i-1))) continue;;
					if(c[i]<=popc[S]-k||s[popc[S]+1]==0) f[S|(1<<(i-1))][k]=(f[S|(1<<(i-1))][k]+f[S][k])%mo;
					else f[S|(1<<(i-1))][k+1]=(f[S|(1<<(i-1))][k+1]+f[S][k])%mo;
				}
			}
		}
		ll ans=0;
		for(int i=m; i<=n; i++) {
			ans=(ans+f[(1<<n)-1][i])%mo;
		}
		cout<<ans;
	}

}
