#include<bits/stdc++.h>
using namespace std;

ifstream fin("polygon.in");
ofstream fout("polygon.out");
#define cin fin
#define cout fout

const int N=5e3+5,M=N<<1;
using i64=long long;
const i64 mod=998244353;

int n,a[N];
i64 dp[M];

signed main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	int mx=a[n]*2;
	dp[0]=1;
	i64 ans=0,qp=1;
	for(int i=1;i<=n;++i,qp=qp*2%mod){
		i64 cnt=qp;
		for(int j=a[i];j<=2*a[i];++j)
			(cnt+=mod-dp[j-a[i]])%=mod;
		(ans+=cnt)%=mod;
		for(int j=mx;j>=a[i];--j)
			(dp[j]+=dp[j-a[i]])%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}

struct Code{
	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }
	~Code(){ cout.flush(),fin.close(),fout.close(); }
} wtl;