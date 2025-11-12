#include<bits/stdc++.h>
using namespace std;
int n;
bool k[25];
bool a[500005][25];
bool l[25];
int dp[500005];
void bian(int i,int x){
	int top;
	while(x>0){
		a[i][++top]=x%2;
		x/=2;
	}
}
void biank(int x){
	int top;
	while(x>0){
		k[++top]=x%2;
		x/=2;
	}
}
void ladd(int i){
	for(int j=1;j<=21;j++){
		if(l[j]+a[i][j]>1){
			l[j]=0;
		}
		else{
			l[j]=l[j]+a[i][j];
		}
	}
}
bool sf(){
	for(int j=1;j<=21;j++){
		if(k[j]!=l[j]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	int x;
	cin>>x;
	biank(x);
	for(int i=1;i<=n;i++){
		cin>>x;
		bian(i,x);
	}
	
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			ladd(j);
			if(sf()){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
		
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	
} 