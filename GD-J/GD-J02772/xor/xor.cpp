#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005][21],dp[500001][2],sum;
void f(int x,int y){
	int i=0;
	while(x){
		s[y][i++]=x%2;
		x/=2;
	} 
}
int f1(int x,int y){
	for(int i=0;i<21;i++){
		if((s[y][i]-s[x-1][i])%2!=s[n+1][i])return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	f(k,n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f(a[i],i);
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0];
		for(int j=i;j<=n;j++){
			if(f1(i,j)){
				if(dp[i-1][1]<j){
					if(dp[i-1][1]<i){
						dp[i][0]++;
						dp[i][1]=j;
					}
					else dp[i][1]=dp[i-1][1];
				}
				else if(dp[i-1][1]>j){
					dp[i][1]=j;
				}
				break;
			}
		}
	}
	cout<<dp[n][0];
	return 0;
} 
