#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,MOD=998244353;
int n;
int a[N];
int f[4][N<<1];
int qpow(int a,int b){
	int ans=1;
	while (b){
		if (b&1) (ans*=a)%=MOD;
		(a*=a)%=MOD,b>>=1;
	}
	return ans;
}
int res;
signed main(){
#ifndef DEBUG
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("polygon\\polygon4.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j+a[i]<=(a[i]<<1);j++)
			(res+=f[3][j]+f[2][j])%=MOD;
		for (int j=a[n]<<1;j>=a[i];j--){
			(f[1][j]+=f[0][j-a[i]])%=MOD;
			(f[2][j]+=f[1][j-a[i]])%=MOD;
			(f[3][j]+=f[2][j-a[i]]+f[3][j-a[i]])%=MOD;
		}
	}
	cout<<(((qpow(2,n)-1-n-(n*(n-1)/2))-res)%MOD+MOD)%MOD<<"\n";
}
// 小恐龙 4754 9:16

// 小恐龙 5390 9:22

// 两连死于飞鸟，红温睡觉 9:30

// 小恐龙 8392 11:11 飞鸟 again

// 14621 11:33

// 欸原来 J 组比的不是小恐龙分数吗

// 接着睡