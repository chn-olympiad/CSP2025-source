#include<bits/stdc++.h>
using namespace std;
int a[5005],s[5005];
const int mod=998244353;
long long ans=0;
void dfs(int non,int s,int sum,int mx){
	if(non>=2){
		if(sum>mx){
			ans=(ans+1)%mod;
			for(int m=1;m<=s-1;m++){
				long long cnt=1;
				for(int j=m+1;j<=s-1;j++){
					cnt*=j;
				}
				long long cnt2=1;
				for(int j=1;j<=s-1-m;j++){
					cnt2*=j;
				}
				ans=(ans+(cnt/cnt2)%mod)%mod;
			}
			return;
		}
	}
	for(int i=s-1;i>=1;i--){
		dfs(non+1,i,sum+a[i],mx);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mxx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxx=max(mxx,a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(mxx==1){
		for(int i=3;i<=n;i++){
			long long cnt=1;
			for(int j=i+1;j<=n;j++){
				cnt*=j;
			}
			long long cnt2=1;
			for(int j=1;j<=n-i;j++){
				cnt2*=j;
			}
			ans=(ans+(cnt/cnt2)%mod)%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		int mx=a[i];
		if(mx>=s[i-1])continue;
		dfs(0,i,0,mx);
	}
	cout<<ans;
	return 0;
}