#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int l[5005];
	int n;
	cin>>n;
	int maxl=-1e3;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		sum+=l[i];
		if(l[i]>maxl) maxl=l[i];
	}
	if(maxl==1){
		long long dp[n+10];
		dp[4]=1;
		for(int i=5;i<=n;i++){
			dp[i]=dp[i-1]*i+1;
			dp[i]%=9982443530000;
		}
		cout<<dp[n]%998244353;
		fclose(stdin);
		fclose(stdout);
		return 0; 
	} 
	if(n==3&&sum>2*maxl){
		cout<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(n==3&&sum<=2*maxl){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	//239382502
	//613452425
	return 0;
}