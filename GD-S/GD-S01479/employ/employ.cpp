#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
int n,m,dp[1<<18][19],c[30];
STR s;
LL ans;
const int mod=998244353;
// dp[S][i]: 每一个员工选择的状态为 S，i 个人 Fail 的方案数。
void added(int &a,int b) {a+=b;if(a>=mod) a-=mod;return ;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	if(n<=18){
		for(int i=1;i<=n;++i) cin>>c[i];
		sort(c+1,c+n+1),dp[0][0]=1;
		for(int S=0;S<(1<<n)-1;++S){
			int cnt=0;
			for(int j=0;j<n;++j) cnt+=((S>>j)&1);
			for(int i=0;i<=cnt;++i){
				for(int t=0;t<n;++t){
					if((S>>t)&1) continue;
					added(dp[S|(1<<t)][i+(c[t+1]<=i || s[cnt]=='0')],dp[S][i]);
				}
			}
		}
//		for(int S=0;S<(1<<n);++S)
//			for(int j=0;j<=n;++j) cerr<<"dp["<<S<<"]["<<j<<"]="<<dp[S][j]<<"\n";
		for(int j=0;j<=n-m;++j) ans=(ans+dp[(1<<n)-1][j])%mod;
		cout<<ans<<"\n";
	}else if(m==n){
		for(int i=0;i<n;++i)
			if(s[i]=='0') {cout<<"0\n",exit(0);}
		for(int i=1;i<=n;++i)
			if(!c[i]) {cout<<"0\n",exit(0);}
		for(int i=1;i<=n;++i) ans=(ans*i)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}

/*
input1:

3 2
101
1 1 2

output1:

2

input2:

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

output2:

2204128
*/
