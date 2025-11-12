#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=25,M=(1<<19)+10;
const int P=998244353;
int n,m,c[N];
string s;
LL f[M][N];
int work() {
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++) {
		int cnt=__builtin_popcount(i);
		for(int j=1;j<=n;j++) {
			if((i>>(j-1))&1) {
				for(int k=0;k<=n;k++) {
					if(cnt-1-k<c[j]&&s[cnt-1]=='1') f[i][k+1]=(f[i][k+1]+f[i^(1<<(j-1))][k])%P;
					else f[i][k]=(f[i][k]+f[i^(1<<(j-1))][k])%P;
//					cout<<"  "<<i<<"    "<<(i^(1<<(j-1)))<<' '<<k<<' '<<f[i^(1<<(j-1))][k]<<'\n';
				}
			}
		}
	}
	LL ans=0;
	for(int k=m;k<=n;k++) {
		ans=(ans+f[(1<<n)-1][k])%P;
	}
	cout<<ans;
	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) {
		work();
	}
	return 0;
}

