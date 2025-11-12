#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum[5001];
long long ans=0;
bool f=false;
const long long mod=998244353;
void dfs(int now,int r,int num,int k,int cnt){
	if(num==k){
		if(2*a[r]<sum[r]-cnt) ans++;
		else f=true;
		return ;
	}
//	if(now>=r or f) return ;
	if(now>=r) return ;
	dfs(now+1,r,num+1,k,cnt+a[now]);
//	if(f) return ;
	dfs(now+1,r,num,k,cnt);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);//最大值为a[i]
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
	for(int i=3;i<=n;i++){
		if(sum[i]>2*a[i]) ans++;
		else continue;
		ans%=mod;
		for(int k=1;k<=i-3;k++){
			f=false;
			dfs(1,i,0,k,0);
		}
//		for(int k=0;k<i;k++){
//			if(i-k<3) break;
//			if(sum[i]-sum[k]<=a[i]*2) break;
//			ans+=(1<<k)-1;
//			ans%=mod;
//		}
	}
	cout<<ans;
	return 0;
}