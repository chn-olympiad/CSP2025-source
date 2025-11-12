#include<bits/stdc++.h>
using namespace std;
const int N=19,mod=998244353;
int n,m,c[N],dp[1<<N][N];
string str;
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m>>str;str=' '+str;
	for(int i=0;i<n;i++)cin>>c[i];
	dp[0][0]=1;
	for(int s=0;s<(1<<n);s++){
		int cnt=__builtin_popcount(s);
		for(int i=0;i<=cnt;i++){
			//cerr<<s<<' '<<i<<' '<<dp[s][i]<<'\n';
			if(!dp[s][i])continue;
			for(int k=0;k<n;k++){
				if((s>>k)&1)continue;
				int ss=(s^(1<<k)),o=(str[cnt+1]=='1'&&c[k]>cnt-i);
				//cerr<<'$'<<ss<<' '<<i+o<<' '<<(str[cnt+1]=='1')<<' '<<k<<' '<<c[k]<<' '<<cnt-i<<'\n';
				(dp[ss][i+o]+=dp[s][i])%=mod;
			}
		}
	}
	int sum=0;
	for(int i=m;i<=n;i++)(sum+=dp[(1<<n)-1][i])%=mod;
	cout<<sum<<'\n';
}
