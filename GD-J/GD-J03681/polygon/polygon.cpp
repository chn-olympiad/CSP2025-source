#include<bits/stdc++.h>
#define i64 long long
using namespace std;
const int maxn=5000+5;
const int mod=998244353;
void solve();
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
int a[maxn],sum[maxn];
int ans=0;
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int l=3;l<=n;l++){
		for(int i=1,j=i+l-1;j<=n;i++,j++){
			int s=sum[j]-sum[i-1];
			if(s>a[j]*2){
				ans%=mod;
				ans++;
				ans%=mod;
			}
		}
	}
	cout<<ans;
}

