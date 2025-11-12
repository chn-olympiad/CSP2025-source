#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e4+10;
const long long mod=998244353;
long long a[5*maxn];
long long sum[5*maxn];
void solve(){
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	} 
	long long ans=0;
	for(long long i=3;i<=n;i++){
		long long l=1,r=i;
		while(r<=n){
			if(2*a[r]<sum[r]-sum[l-1])
			 	ans++;
			 r++;
			 l++;
		}
	}
	cout<<ans*2-1;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long T=1;
	//cin>>T
	while(T--){
		solve();
	}
	return 0;
}
