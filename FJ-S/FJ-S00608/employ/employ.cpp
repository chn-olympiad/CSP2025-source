#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace qwq{
	const int N=514,p=998244353;
	int f[N][N],g[N][N],n,m,c[N],P[N],sumc[N];
	char s[N];
	signed mian(){
//		cin >> n >> m >> (s+1);
//		for(int i=1;i<=n;++i){
//			int x;
//			cin >> x;
//			++c[x];
//		}
//		sumc[0]=c[0];
//		for(int i=1;i<=n;++i) sumc[i]=sumc[i-1]+c[i];
//		memset(f,0,sizeof(f));
//		f[0][0]=1;
//		int ans=0;
//		for(int i=0;i<=n;++i){
//			for(int j=i;j<=n;++j){
//				if(j<n && s[j+1]=='0'){
//					for(int k=0;k<=n;++k){
//						g[j+1][k+1]=(g[j+1][k+1]+f[j][k]*(k+1))%p;
//					}
//				}
//				for(int o=1;o<=c[i];++o){
//					for(int k=0;k<=n;++k){
//						f[j][k]=(f[j][k]+f[j][k+1])%p;
//					}
//				}
//				if(j<n && s[j+1]=='1'){
//					//0
//					for(int k=0;k<=n;++k){
//						if(sumc[i]+k-j>=1) g[j+1][k]=(g[j+1][k]+f[j][k]*(sumc[i]+k-j))%p;
//					}
//					//1
//					for(int k=0;k<=n;++k){
//						f[j+1][k+1]=(f[j+1][k+1]+f[j][k]*(k+1))%p;
//					}
//				}
//			}
//			for(int j=i;j<=n;++j){
//			}
//			for(int j=i;j<=n;++j){
//			}
//			for(int j=0;j<=n;++j){
//				for(int k=0;k<=n;++k){
//					cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
//				}
//			}
//			if(i<=n-m){
//				ans=(ans+f[n][0])%p;
//			}
//			memmove(f,g,sizeof(f));
//		}
//		cout << ans << endl;
		cin >> n >> m >> (s+1);
		int ans=0;
		for(int i=1;i<=n;++i) cin >> c[i];
		for(int i=1;i<=n;++i) P[i]=i;
		do{
			int cnt0=0;
			for(int i=1;i<=n;++i){
				if(s[i]=='0') ++cnt0;
				else if(c[P[i]]<=cnt0) ++cnt0;
			}
			if(n-cnt0>=m) ++ans;
		}while(next_permutation(P+1,P+1+n));
		cout << ans << endl;
		return 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	qwq::mian();
	return 0;
}
