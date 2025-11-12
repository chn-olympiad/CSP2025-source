#include<bits/stdc++.h>
//#define int long long
using namespace std;
const  int maxn=1e3+1000;
int n,k;
int a[maxn],sum[maxn]; 
int ans=0;
int dp[maxn];
int maxx=0;
int  main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i] = sum[i-1] xor a[i];
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0)
			ans++;
		cout<<ans;
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
		int l = i,r = i,x = sum[r] xor sum[l-1];
		while(r<=n){
				dp[r]=max(dp[r],dp[l-1]);
				if(x!=k){
					r++;
				}else{
					dp[r] = max(dp[r],dp[l-1]+1);
					l++;
//					cout<<dp[r]<<' ';
				}
				x = sum[l-1] xor sum[r];
			}
		}
		cout<<dp[n];
	}
	else{
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)
					ans++;
				else if(a[i+1]!=1&&abs(a[i]-a[i+1])==1){
					ans++; 
				}
			}
				
			cout<<ans;
		}
	}
	return 0;
}

