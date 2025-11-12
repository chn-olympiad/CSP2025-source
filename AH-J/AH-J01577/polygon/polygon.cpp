//已经没有心情写注释了
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5010],sum[5010],ans,f[5010];
//struct f{
//	ll t,a;
//};
void dfs(ll cnt,ll sum,ll maxn){
	if(cnt>=3){
		ans++;
	}
	for(ll i=1;i<=n;i++){
		if(f[i]==0){
			if(cnt<2){
				f[i]=1;
				dfs(cnt+1,sum+a[i],max(maxn,a[i]));
				f[i]=0;
			}else{
				if(sum+a[i]>max(maxn,a[i])){
					f[i]=1;
					dfs(cnt+1,sum+a[i],max(maxn,a[i]));
					f[i]=0;
				}
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans/n/(n-1)/(n-2);
	//for(ll len=3;len<=n;len++){
	//	deque<f>q;
	//	for(ll i=1;i<len;i++){
	//		while(!q.empty()&&q.back().a<a[i]) q.pop_back();
	//		q.push_back({i,a[i]});
	//	}
	//	for(ll r=len;r<=n;r++){
	//		while(!q.empty()&&q.back().a<a[r]) q.pop_back();
	//		while(!q.empty()&&q.front().t<=r-len) q.pop_front();
	//		q.push_back({r,a[r]});
	//		if(sum[r]-sum[r-len]>q.front().a){
	//			cnt++;
	//			cnt%=998244353;
	//		}
	//	}
	//}
	//if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])){
	//	dp[3][3]=1;
	//}
	//for(ll i=3;i<=n;i++){
	//	for(ll k=3;k<=i;k++){
	//		if(a[i]<sum[i-1]){
	//			dp[i][k]=dp[i-1][k]+(k-1)*(k-2)/k;
	//		}else{
	//			dp[i][k]=dp[i-1][k];
	//		}
	//		dp[i][k]%=998244353;
	//	}
	//}
	//ll sum=0;
	//for(ll i=1;i<=n;i++){
	//	sum+=dp[n][i];
	//}
	//cout<<sum;
	return 0;
} 
