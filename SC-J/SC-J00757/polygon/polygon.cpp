#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],dp[5005];
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[2]+a[3]>a[1])cout<<1;
		else cout<<0;
	}
	else{
//		dp[3]=1;
		for(int j=n;j>=3;j--){
			//cout<<j<<":";
			dp[j]=dp[j+1];
			if(!(a[j]<s[j-1])/*结论公式*/)continue;
			for(int i=j-1;i>=1;i--){
				for(int k=0;k<i-1;k++){
					if(s[i]-s[k]>a[j]){
						if(k==0)dp[j]+=1,dp[j]%=998244353;
						else dp[j]+=2,dp[j]%=998244353;
					}
				}
			}
			//cout<<endl;
		}
		cout<<dp[3]%998244353;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}