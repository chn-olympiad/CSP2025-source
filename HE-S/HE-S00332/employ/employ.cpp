#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[510],c[510],f[300010][20];
const int mod=998244353;
int popcount(int x){
	int ans=0;
	while(x){
		ans++;
		x^=x&(-x);
	}
	return ans;
}
signed main(){
//	system("fc replace.out replace3.ans"); return 0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c; cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	if(n>18 && m==n){
		for(int i=1;i<=n;i++){
			if(!a[i]){
				cout<<0;
				return 0;
			}
		}
		if(c[1]==0){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	f[0][0]=1;
	for(int S=0;S<(1<<n)-1;S++){
		int x=popcount(S);
		for(int i=0;i<=x;i++){
			for(int j=1;j<=n;j++){
				if(S&(1<<(j-1))) continue;
				if(c[j]>i && a[x+1]) f[S|(1<<(j-1))][i]=(f[S|(1<<(j-1))][i]+f[S][i])%mod;
				else f[S|(1<<(j-1))][i+1]=(f[S|(1<<(j-1))][i+1]+f[S][i])%mod;
			}
		}
	}
	for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans;
	return 0;
}
