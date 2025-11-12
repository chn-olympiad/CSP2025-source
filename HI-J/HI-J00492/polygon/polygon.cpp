#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long ans,allsum;
int use[25];
void dfs(int now){
	if(now==n+1){
		int tot=0,sum=0,maxa=0;
		for(int i=1;i<=n;++i){
			if(use[i]==1){
				tot++;
				sum+=a[i];
				maxa=max(maxa,a[i]);
			}
		}
		if(tot>=3&&sum>maxa*2){
			ans++;
		}	
		return ;
	}
	use[now]=1;
	dfs(now+1);
	use[now]=0;
	dfs(now+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int high=0; 
	for(int i=1;i<=n;++i){
		cin>>a[i];
		high=max(high,a[i]);
	}
	if(n<=25){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(high==1){
		long long pre[5005];
		pre[0]=1;
		for(int i=1;i<=n;++i){
			pre[i]=pre[i-1]*i%mod;
		}
		for(int i=3;i<=n;++i){
			ans+=(pre[n]/(pre[i]*pre[n-i]%mod))%mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		long long dp[50004];
		for(int i=1;i<=n;++i){
			allsum+=a[i];
			if(i>=3){
				for(int j=allsum;j>=1;--j){
					if(j-a[i]>0){
						dp[i]+=dp[j-a[i]];
						dp[i]%=mod;
					}
					else{
						break;
					}
				} 
			}
		}
		cout<<0;
		return 0;
	} 
	return 0;
}
