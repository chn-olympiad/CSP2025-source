#include<bits/stdc++.h>
using namespace std;
int a[500010];
pair<int,int> p[500010];
int cnt=0;
int dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n*n>=1000000000){
		int maxx=0;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,a[i]);
		if(maxx==1&&k==1){
			for(int i=1;i<=n;i++)
				ans+=a[i];
			cout<<ans;
			return 0;
		}
		else if(maxx==1&&k==0){
			for(int i=1;i<=n;i++)
				ans+=!a[i];
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]&&a[i]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int o=a[i];
		if(o==k){
			p[++cnt]={i,i};
		}
		for(int j=i+1;j<=n;j++){
			o=o xor a[j];
			if(o==k)
				p[++cnt]={i,j};
		}
	}
	sort(p+1,p+cnt+1);
	for(int i=1;i<=cnt;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(p[j].second<p[i].first){
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
