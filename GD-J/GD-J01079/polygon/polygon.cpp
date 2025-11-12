#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
const int N=5e3+114;
int n;
int a[N];
ll s[N];
ll dp[N][N]; 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dp[i][0]=i-1;

	for(int i=1;i<=n;i++){
		for(int j=a[i];j>=1;j--){
			dp[i][j]+=dp[i-1][j];
			if(a[i-1]>j) dp[i][j]+=dp[i-1][j]+1;
			else dp[i][j]+=dp[i-1][j-a[i-1]];
		}
	}
	
	
	ll ans=0;
 	for(int i=3;i<=n;i++){
 		ans=(ans%MOD+dp[i][a[i]]%MOD)%MOD;
 		
	}
	
 		
	cout<<ans<<endl;
	//为什么要大于为什么要大于为什么要大于为什么要大于 
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	return 0;
} 
