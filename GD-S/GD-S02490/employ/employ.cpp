#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,p=998244353;
string s;
int n,m,c[N],dp[N][N],f[1<<18][20],cnt[N];
void add(int &x,int y) {x+=y;if(x>=p) x-=p;}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) cin>>c[i];
	if(n<=18) {
		f[0][0]=1;
		for(int i=0; i<(1<<n)-1; i++) {
			int pc=__builtin_popcount(i);
			for(int j=0; j<=pc; j++) {
				for(int k=1; k<=n; k++) {
					if(i&(1<<k-1)) continue;
					if(c[k]<=j||s[pc]=='0') add(f[i|(1<<k-1)][j+1],f[i][j]);
					else add(f[i|(1<<k-1)][j],f[i][j]);
				}
			}
		}
		int ans=0;
		for(int i=0; i<=n-m; i++) add(ans,f[(1<<n)-1][i]);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n) {
		for(int i=0; i<s.size(); i++) if(s[i]=='0') return cout<<0<<"\n",0;
		for(int i=1; i<=n; i++) if(!c[i]) return cout<<0<<"\n",0;
		int mul=1;
		for(int i=1; i<=n; i++) mul=mul*i%p;
		cout<<mul<<"\n";
		return 0;
	}
	if(m==1) {
		for(int i=1; i<=n; i++) cnt[c[i]]++;
		for(int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
		int mul=1,jzc=0;
		for(int i=1; i<=n; i++) {
			if(s[i-1]=='1') {
				mul=mul*(cnt[i-1]-jzc)%p;
				jzc++;
			}
		}
		for(int i=1; i<=n-jzc; i++) mul=mul*i%p;
		int al=1;
		for(int i=1; i<=n; i++) al=al*i%p;
		cout<<(al-mul+p)%p<<"\n";
		return 0;
	}
	sort(c+1,c+n+1);
	int pos=0;
	for(int i=1; i<=n; i++) if(!c[i]) pos=i;
	dp[pos][0]=1;
	for(int i=pos; i<n; i++) {
		for(int j=0; j<=i; j++) {
			int val=j+1+min(i-j,c[i+1]-1);
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*val%p)%p;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(i+1-val)%p)%p;
		}
	}
	int ans=0;
	for(int i=m; i<=n; i++) ans=(ans+dp[n][i])%p;
	cout<<ans<<"\n";
	return 0;
}
/*
18 9
111111111111111111
0 0 0 0 0 1 2 3 3 4 4 5 6 6 9 14 16 18

没时间整活了，祝我不挂分/kx 
*/
