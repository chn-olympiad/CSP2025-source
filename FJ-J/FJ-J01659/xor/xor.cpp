#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,a[200001],dp[200001][256],d,l,mx[256],flag=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag=0;
		}
	}
	if(flag){
		flag=0;
		for(int i=1;i<=n;i++){
			flag=(flag+a[i])%2; 
			if(flag==k){
				d++;
				flag=0;
			}		
		}
		cout<<d;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<256;j++){
			if(j==a[i]){
				dp[i][j]=mx[j]+1;
			}
			l=j;
			l^=a[i];
			dp[i][j]=max(dp[i][j],dp[i-1][l]);
			d=max(d,dp[i][j]);
			if(j==k){
				mx[j]=max(mx[j],dp[i][j]);
			}
		}
	}
	if(a[1]==k){
		d++;
	} 
	cout<<d;
	return 0;
}
