#include<bits/stdc++.h>

using namespace std;

const long long mod=998244353;
long long n,m,f[1<<18][18],ans,c[505],popcount[1<<18],cnt[505];
char s[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18) {
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++) popcount[i]=popcount[i>>1]+(i&1);
		for(int i=0;i<(1<<n);i++) for(int j=0;j<=popcount[i];j++) if(f[i][j]) for(int k=1;k<=n;k++) if((i&(1<<(k-1)))==0) f[i|(1<<(k-1))][j+(j>=c[k]||s[popcount[i]+1]=='0')]=(f[i|(1<<(k-1))][j+(j>=c[k]||s[popcount[i]+1]=='0')]+f[i][j])%mod;
		for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
		cout<<ans;
		return 0;
	}
	if(m==n) {
		for(int i=1;i<=n;i++) if(s[i]=='0') {
			cout<<"0";
			return 0;
		}
		for(int i=1;i<=n;i++) if(c[i]==0) {
			cout<<"0";
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	if(m==1) {
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		long long mul=1;
		for(int i=1;i<=n;i++) cnt[c[i]]++;
		int Cnt=cnt[0],now=0;
		for(int i=1;i<=n;i++) if(s[i]=='1') mul=mul*Cnt%mod,Cnt--,Cnt+=cnt[++now];
		else Cnt+=cnt[++now];
		for(int i=1;i<=Cnt;i++) mul=mul*i%mod;
		cout<<(ans-mul+mod)%mod;
	}
	return 0;
}
