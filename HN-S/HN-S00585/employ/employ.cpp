#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod=998244353;
int n,m,c[50001],f[11][11][1ll<<18],g[1000001];
string s;
void solve(){
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
		if(s[1]=='0'||c[i]==0)f[i][0][(1ll<<(i-1))]=1;
		else f[i][1][(1ll<<(i-1))]=1;
	for(int i=0;i<(1ll<<n);i++){
		int q=0;
		for(int j=1;j<=n;j++)
			if(i&(1ll<<(j-1)))q++;
		int t1=0;
		for(int j=1;j<=n;j++)
			if(!(i&(1ll<<(j-1))))g[++t1]=j;
		for(int p=0;p<=q;p++) 
			for(int j=1;j<=n;j++)
				if(i&(1ll<<(j-1)))
					for(int k=1;k<=t1;k++)
						if(s[q+1]=='0'||p>=c[g[k]])f[g[k]][p][i|(1ll<<(g[k]-1))]+=f[j][p][i],f[g[k]][p][i|(1ll<<(g[k]-1))]%=mod;
						else f[g[k]][p+1][i|(1ll<<(g[k]-1))]+=f[j][p][i],f[g[k]][p+1][i|(1ll<<(g[k]-1))]%=mod;
	}
	int sg=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j<=n;j++){
			sg+=f[i][j][(1ll<<n)-1];
			sg%=mod;
		}
	cout<<sg<<endl;
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
