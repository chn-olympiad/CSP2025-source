#include<bits/stdc++.h>
using namespace std;
int xoor(int a,int b){
	int out=0;
	int i=1;
	if(a==b&&a==0){
		return 1;
	}
	while(a||b){
		int a1,b1;
		a1=a%int(pow(2,i));
		b1=b%int(pow(2,i));
		if(a1==b1){
			out+=pow(2,i-1);
		}
		a-=a1;
		b-=b1; 
		i++;
	}
	return out;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[1001];
	int dp[101][101]={};
	int f[101]={};
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=xoor(a[i],a[i]);
		for(int y=i+1;y<=n;y++){
			dp[i][y]=xoor(dp[i][y-1],a[y]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp[i][j]==k){
				f[j]=max(f[j-1],f[i-1]+1);
			}
			else{
				f[j]=max(f[j],f[j-1]);
			} 
		}
	}
	cout<<f[n];
	return 0;
} 