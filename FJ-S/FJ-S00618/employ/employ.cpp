#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define lc(p) ((p)*2)
#define rc(p) ((p)*2+1)
#define mkpr make_pair
#define fir first
#define sec second
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,c[N],a[N];
string s;
LL ans;
int dp[262150][19];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		a[i]=i;
	}
	if(n<=10) {
		do {
			int cnt=0;
			for(int i=1; i<=n; i++) {
				if(cnt>=c[a[i]]) {
					cnt++;
					continue;
				}
				if(s[i]=='0') {
					cnt++;
				}
			}
			if(n-cnt>=m)ans++;
		} while(next_permutation(a+1,a+1+n));
		cout<<ans;
	} else if(n<=18) {
		dp[0][0]=1;
		for(int i=0; i<(1<<n); i++) {
			int cnt=1;
			for(int j=1; j<=n; j++) {
				if((i>>(j-1))&1)cnt++;
			}
			for(int k=0; k<cnt; k++) {
				for(int j=1; j<=n; j++) {
					if((i>>(j-1))&1)continue;
					int t=0;
					if(s[cnt]=='0')t=1;
					if(k>=c[j])t=1;
					(dp[i|(1<<(j-1))][k+t]+=dp[i][k])%=mod;
					//	cout<<i<<' '<<k<<' '<<dp[i][k]<<' '<<t<<' '<<cnt<<endl;
					//	cout<<(i|(1<<(j-1)))<<' '<<k+t<<' '<<dp[i|(1<<(j-1))][k+t]<<'\n';
				}
			}
			//	cout<<endl;
		}
		//	cout<<sizeof dp<<endl;
		LL ans=0;
		for(int j=0; j<=n-m; j++) {
			(ans+=dp[(1<<n)-1][j])%=mod;
			//		cout<<dp[(1<<n)-1][j]<<' ';
		}
		cout<<ans;
	} else {
		LL ans=1;
		for(int i=1; i<=n; i++) {
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	return 0;
}
/*
A

所有人均能做出

c=0

00000111122222

c=1 2

在 p 前至少有 cp 个

m=n

m=1

-[=0]

cnt>=c[i]

s[i]=0


*/
