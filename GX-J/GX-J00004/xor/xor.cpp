#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int s[a+1],dp[a+2][a+2];
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			if(i==j){
				dp[i][j]=s[i];
			}else{
				dp[i][j]=(dp[i-1][j]) | (s[i]);
			}
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			if(dp[i][j]==b){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
