#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5011,mod= 998244353;
int n;
int a[N],now;
int cnt[N*100],ans;
int sum[N*100];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	cnt[a[1]+a[2]]++;
	now=a[1]+a[2];
	for(int i=now;i>=1;i--){
		sum[i]=cnt[i];
		sum[i]=(sum[i]+sum[i+1]%mod)%mod;
	}
	for(int i=3;i<=n;i++){
		ans=(sum[a[i]+1]+ans)%mod;
		for(int j=now;j>=1;j--){
			if(cnt[j])cnt[j+a[i]]=(cnt[j+a[i]]+cnt[j])%mod;
		}
		for(int j=1;j<i;j++){
			cnt[a[i]+a[j]]++;
		}
		now+=a[i];
		for(int j=now;j>=1;j--){
			sum[j]=cnt[j];
			sum[j]=(sum[j]+sum[j+1])%mod;
		}
	}
	cout<<ans;
	return 0;
}
