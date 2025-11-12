#include<bits/stdc++.h>
using namespace std;
long long a[50005],cnt1,dp[50005],b[5005],d[500005];
long long ans,n,mod=998244353,x,idx;
void dfs(int pos,long long mx,long long sum){
	if (pos>=n+1){
		if (sum>mx*2) ans++;
		return ;
	}
	dfs(pos+1,max(mx,a[pos]),sum+a[pos]);
	dfs(pos+1,mx,sum);
}
struct f{
	long long id,x;
}dp1[500005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if (n<=3){
		if (n<3) cout<<0;
		else{
			for (int i=1;i<=n;i++){
				cin>>a[i];
			}
			sort(a+1,a+n+1);
			if ((a[1]+a[2])>2*a[3]){
				cout<<1;
			}else cout<<0;
		}
	} else if (n<=20){
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		dfs(1,0,0);
		ans%=998244353;
		cout<<ans;
	}else{
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		if (a[n]==1){
			for (int i=1;i<=n;i++){
				x=1;
				for (int j=n;j>=n-i+1;j--){
					x*=j;
					x%=mod;
				}
				ans+=x;
				ans%=mod;
			}
		}else{
			for (int i=1;i<=n;i++){
				b[i]=b[i-1]+a[i];
			}
			for (int i=1;i<=n;i++){
				for (int j=0;j<i;j++){
					d[++cnt1]=b[i]-b[j];
				}
			}
			sort(d+1,d+cnt1+1);
			for (int i=1;i<=n;i++){
				if (b[i]<=a[i]*2) ans+=0;
				else{
					x=b[i]-a[i]*2-1;
					idx=upper_bound(d+1,d+cnt1,x)-d;
					idx--;
					ans+=idx;
					ans%=mod;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
