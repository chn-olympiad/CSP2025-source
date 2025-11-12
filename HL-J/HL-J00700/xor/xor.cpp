#include <bits/stdc++.h>
using namespace std;
int n,k,a[1001],dp[1001][1001],s,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			if(i==j){
				if(a[i]==k){
					dp[i][j]=1;
				}
			}
			else{
				p=i+1;
				s+=a[i];
				while(p<=j){
					s=(s^a[p]);
					p++;
				}
				if(s==k){
					dp[i][j]=1;
				}
				s=0;
				for(int q=i+1;q<=j;q++){
					dp[i][j]=max(dp[i][j],dp[i][q-1]+dp[q][j]);
				}
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
