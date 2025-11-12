#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,ans;
ll a[100010][5],dp[202][202];
bool flag2,flag3;
ll cur[100010],f[100010];
//inline ll max(ll a,ll b){return a>b?a:b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--){
		ans=0,flag2=flag3=1;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)flag2=0;
			if(a[i][3]!=0)flag3=0;
		}
		if(n<=200){
			for(ll i=0;i<=200;i++)
				for(ll j=0;j<=200;j++)dp[i][j]=0;
			for(ll l=1;l<=n;l++){
				for(ll i=min(l,n/2);i>=0;i--){
					for(ll j=min(n/2,l-i);j>=0;j--){
						ll cur=dp[i][j];
						if(l-i-j<n/2)cur=max(cur,dp[i][j]+a[l][3]);
						if(i)cur=max(cur,dp[i-1][j]+a[l][1]);
						if(j)cur=max(cur,dp[i][j-1]+a[l][2]);
//						i?(dp[i][j]=dp[i][j]<dp[i-1][j]+a[l][1]?dp[i-1][j]+a[l][1]:dp[i][j]):i;
//						j?(dp[i][j]=dp[i][j]<dp[i][j-1]+a[l][2]?dp[i][j-1]+a[l][2]:dp[i][j]):j;
						dp[i][j]=cur;
						ans=ans<cur?cur:ans;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(flag2&&flag3){
			for(ll i=1;i<=n;i++)cur[i]=a[i][1];
			sort(cur+1,cur+n+1);
			for(ll i=n;i>n/2;i--)ans+=cur[i];
			cout<<ans<<"\n";
			continue;
		}
		if(flag3){
			for(ll i=0;i<=n/2;i++)f[i]=0;
			for(ll i=1;i<=n;i++){
				for(ll j=min(i,n/2);j>=0;j--){
					if(i-j<=n/2)f[j]=max(f[j],f[j]+a[i][2]);
					if(j)f[j]=max(f[j],f[j-1]+a[i][1]);
					ans=max(ans,f[j]);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}/*
dp[i][j]表示1部门选了i个人，2选了j个人，3选了n-i-j个人的最大值
dp[i][j] dp[i-1][j][k]+a[1]
dp[i][j] dp[i][j-1][k]+a[2]
dp[i][j] dp[i][j][k-1]+a[3]
*/
