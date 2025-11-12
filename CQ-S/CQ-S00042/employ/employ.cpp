#include <bits/stdc++.h>
using namespace std;
namespace yhy{
	const int MAXN=505;
	#define int long long
	const int Mod=998244353;
	int n,m;
	int a[MAXN];
	int flag[MAXN];
	string s;
	int f[(1<<18)+5][22][22];
	int main() {
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		std::ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n>>m;
		cin>>s;
		s=" "+s;
		int tot=0;
		for(int i=1;i<=n;i++) {
			flag[i]=s[i]-'0';
			cin>>a[i];
			// cout<<a[i]<<" ";
		}
		if(n<=18) {
			f[0][0][0]=1;
			for(int i=0;i<(1<<n)-1;i++) {
				int cnt=0;
				for(int j=1;j<=n;j++) {
					if((i>>(j-1))&1) {
						cnt++;
					}
				}
				for(int j=1;j<=n;j++) {
					if((i>>(j-1))&1) {
						continue;
					}
					int aim=i+(1<<(j-1));
					for(int k=0;k<=n;k++) {
						for(int p=0;p<=n;p++) {
							if(!f[i][k][p]) continue;
							if(!flag[cnt+1] || a[j]<=k) {
								f[aim][k+1][p]=(f[aim][k+1][p]+f[i][k][p])%Mod;
							}
							else {
								f[aim][0][p+1]=(f[aim][0][p+1]+f[i][k][p])%Mod;
							}
						}
					}
				}
			}
			int ans=0;
			// for(int i=1;i<(1<<n);i++) {
			// 	cout<<"i:"<<i<<" ";
			// 	for(int j=1;j<=n;j++) {
			// 		if((i>>(j-1))&1) {
			// 			cout<<1;
			// 		}
			// 		else {
			// 			cout<<0;
			// 		}
			// 	}
			// 	for(int j=0;j<=n;j++) {
			// 		for(int k=0;k<=n;k++) {
			// 			if(f[i][j][k]) {
			// 				cout<<" j:"<<j<<" k:"<<k<<" f[i][j][k]:"<<f[i][j][k]<<'\n';
			// 			}
			// 		}
			// 	}
			// }
			for(int j=0;j<=n;j++) {
				for(int k=m;k<=n;k++) {
					ans=(ans+f[(1<<n)-1][j][k])%Mod;
				}
			}
			cout<<ans<<'\n';
		}
		else {
			cout<<0<<'\n';
		}
		return 0;
	}
}
signed main() {
	yhy::main();
	return 0;
}
/*
传奇 n<=500

见数据范围知难度

比较难处理的是算重负的问题

n<=10 用全排列

n<=18 状压 DP

n<=100 暂时不会

感觉这种东西再怎么都需要容斥

卧槽你的 a[i]=0
*/