#include<bits/stdc++.h>
using namespace std;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=500;
	const LL Mod=998244353;
	int n,m,c[N+5],ppc[1<<18];
	string s;
	LL dp[1<<18][20],ans;
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		cin>>n>>m;
		cin>>s;
		for(int i=0;i<n;i++){
			cin>>c[i];
		}
		dp[0][0]=1ll;
		for(int S=0;S<1<<n;S++){
			ppc[S]=ppc[S>>1]+(S&1);
			for(int i=0;i<=ppc[S];i++){
				dp[S][i]%=Mod;
				if(dp[S][i]==0) continue;
				for(int j=0;j<n;j++){
					if(S>>j&1) continue;
					if(s[ppc[S]]=='0'||c[j]<=i) dp[S|1<<j][i+1]+=dp[S][i];
					else dp[S|1<<j][i]+=dp[S][i];
				}
			}
		}
		for(int i=0;i<=n-m;i++){
			ans+=dp[(1<<n)-1][i]%Mod;
		}
		ans%=Mod;
		cout<<ans<<"\n";
		return 0;
	}
}
int main(){
	cs::main();
	return 0;
}
/*
204min Ð´Íê T4 20pts ±©Á¦ 
*/
