#include<bits/stdc++.h>
using namespace std;
int x[22]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
bool x1[22],x2[22];
int s1,s2,s3,n,k,a[500001],ysh;
int dp[7601][7601],ox[7601][7601];
int xrs(int a,int b){
	s1=0;
	s2=0;
	ysh=0;
	memset(x1,0,sizeof(x1));
	memset(x2,0,sizeof(x2));
	while(a>0){
		s1++;
		x1[s1]=a%2;
		a=a/2;
	}
	while(b>0){
		s2++;
		x2[s2]=b%2;
		b=b/2;
	}
	s3=max(s1,s2);
	for(int i=1;i<=s3;i++){
		if(x2[i]!=x1[i]){
			ysh+=x[i];
		}
	}
	return ysh;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			dp[i][i]=1;
		}
		ox[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ox[i][j]=xrs(ox[i][j-1],a[j]);
			if(ox[i][j]==k){
				dp[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			for(int q=j;q<j+i;q++){
				dp[j][j+i]=max(dp[j][j+i],dp[j][q]+dp[q+1][j+i]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
} 