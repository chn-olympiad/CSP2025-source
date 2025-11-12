#include<bits/stdc++.h>
using namespace std;
struct no{
	int val1,val2,val3;
}a[100005];
int dp[105][105][105];
int maxn1[100005],maxn2[100005];
int id1[100005],id2[100005];
bool flag2,flag3;
int ans;
bool cmp1(no x,no y){
	return x.val1>y.val1;
}
bool cmp2(no x,no y){
	return x.val1-x.val2>y.val1-y.val2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		flag2=0;flag3=0;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].val1>>a[i].val2>>a[i].val3;
			if(a[i].val2){
				flag2=1;
			}
			if(a[i].val3){
				flag3=1;
			}
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(i-j,n/2);k++){
						int s=i-j-k;
						dp[j][k][s]=0;
						if(s>n/2){
							continue;
						}
						if(j){
							dp[j][k][s]=max(dp[j][k][s],dp[j-1][k][s]+a[i].val1);
						}
						if(k){
							dp[j][k][s]=max(dp[j][k][s],dp[j][k-1][s]+a[i].val2);
						}
						if(s){
							dp[j][k][s]=max(dp[j][k][s],dp[j][k][s-1]+a[i].val3);
						}
						ans=max(ans,dp[j][k][s]);
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(!flag2 && !flag3){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].val1;
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp2);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].val1;
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=a[i].val2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
