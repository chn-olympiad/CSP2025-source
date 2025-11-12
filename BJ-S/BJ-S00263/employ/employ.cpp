#include <bits/stdc++.h>
using namespace std;
const int N=20,STA=(1<<18),Mod=998244353;
int n,m,c[N],cnt1[STA],dp[2][N][STA];
bool p[N];
vector<int> S[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m; char ch;
	for (int i=1;i<=n;i++) cin>>ch,p[i]=ch-'0';
	for (int i=1;i<=n;i++) cin>>c[i];
	int mx=(1<<n)-1; 
	for (int i=0;i<=mx;i++) {
		for (int j=0;j<n;j++) cnt1[i]+=((i>>j)&1);
		S[cnt1[i]].push_back(i);
	}
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=n;j++) 
			for (int sta=0;sta<=mx;sta++) dp[(i&1)][j][sta]=0;
		for (int j=0;j<i;j++) {
			for (int sta:S[i-1]) {
				for (int k=0;k<n;k++) {
					if (((sta>>k)&1)) continue;
					if (p[i]) {
						if (i-1-j<c[k+1]) dp[(i&1)][j+1][(sta|(1<<k))]=(dp[(i&1)][j+1][(sta|(1<<k))]+dp[((i-1)&1)][j][sta])%Mod;
						else dp[(i&1)][j][(sta|(1<<k))]=(dp[(i&1)][j][(sta|(1<<k))]+dp[((i-1)&1)][j][sta])%Mod;
					}
					else dp[(i&1)][j][(sta|(1<<k))]=(dp[(i&1)][j][(sta|(1<<k))]+dp[((i-1)&1)][j][sta])%Mod;
				}
			}
		}
	}
	int ans=0;
	for (int i=m;i<=n;i++) ans=(ans+dp[(n&1)][i][mx])%Mod;
	cout<<ans<<"\n";
	return 0;
}