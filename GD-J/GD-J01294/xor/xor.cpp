#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],bin[N][33],qzh[N][33],dp[N],sum,p,cnt;
int one,ans;
bool pf=1;
void to_bin(int i){
	int x=a[i];
	int cnt=0;
	while(x){
		bin[i][++cnt]=x%2;
		x/=2;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) pf=0;
		to_bin(i);
		for(int j=1;j<=20;j++){
			qzh[i][j]=qzh[i-1][j]^bin[i][j];
		}
	}
	if(pf){
		if(k){
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1) ans++,i++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		sum=0;
		for(int j=i;j>=1;j--){
			for(int o=j;o<=i;o++){
				sum^=a[o];
			}
			//cout<<i<<' '<<j<<' '<<sum<<'\n';
			if(sum==k){
				cout<<j<<' '<<i<<'\n';
				dp[i]=max(dp[j]+1,dp[i]);
				break;
			}
		}
		//cout<<dp[i]<<' ';
	}
	cout<<'\n'<<dp[n];
	return 0;
}
/*
I can't debug this ****ing program!
maybe I will just get 30 points in this problem
maybe I will get 290 points in CSP-J
maybe I will win the first prize in CSP-J
but I am still not satisfied with this ****ing score
All right,it doesn't matter
I hope I can do well in the coming CSP-S test and win the first prize!
rp++!
*/
