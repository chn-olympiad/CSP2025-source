#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+10,mod=998244353;
int n,a[maxn],ans;
void solve1(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<(1<<(i-1));j++){
			int t=j,sum=0;
			for(int ii=1;t>0;ii++){
				if(t&1)sum+=a[ii];
				t>>=1;
			}
			if(sum>a[i])ans=(ans+1)%mod;
		}
	}
	cout<<ans;
}
void solve(){
	if(1)solve1();
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
