#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool sp,l[501];
	long long n,m,t,ans=0,a[501],num[300001]={0},all[300001],dp[300001][101]={1};
	char c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		num[i]=num[i-1];
		cin>>c;
		if(c=='0'){
			l[i]=false;
			num[i]++;
			sp=false;
		}
		else{
			l[i]=true;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(sp){
		t=0;
		ans=1;
		for(int i=1;i<=n;i++){
			if(a[i]){
				t++;
			}
			ans=(ans*i)%998244353;
		}
		if(t>=m){
			cout<<ans;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<pow(2,n);i++){
		dp[i][0]=1;
		for(int j=1;j<=n;j++){
			if((i/(int)pow(2,j-1))%2){
				all[i]++;
				dp[i][0]*=all[i];
			}
		}
	}
	for(int i=1;i<pow(2,n);i++){
		t=0;
		for(int j=1;j<=n;j++){
			if((i/(int)pow(2,j-1))%2){
				if(l[all[i]]&&(a[j]>num[all[i-(int)pow(2,j-1)]])){
					for(int k=1;k<=n;k++){
						dp[i][k]=(dp[i][k]+dp[i-(int)pow(2,j-1)][k-1])%998244353;
					}
				}
				else{
					for(int k=1;k<=n;k++){
						dp[i][k]=(dp[i][k]+dp[i-(int)pow(2,j-1)][k])%998244353;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			dp[i][0]=(dp[i][0]-dp[i][j]+998244353)%998244353;
		}
	}
	for(int i=m;i<=n;i++){
		ans+=dp[(int)pow(2,n)-1][i];
	}
	cout<<ans;
	return 0;
}
