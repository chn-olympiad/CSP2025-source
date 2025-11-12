#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int Mod=998244353;
int a[N];
long long dp[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=0;
	}
	if(flag||n<=2){cout<<"0";return 0;}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=a[i]-1;j++){
			for(int k=i+1;k<=n;k++)dp[k][j]+=1;
			dp[i][j]+=1;
		}
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<"1";
		else cout<<"0";return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=a[n];j>=0;j--){
			dp[i][j]+=dp[i-1][j];
			if(j-a[i]<0)dp[i][j]+=dp[i-1][0];
			else dp[i][j]+=dp[i-1][j-a[i]];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=a[n];j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=dp[i-1][a[i]];
	}
	cout<<ans;
	return 0;
}
/*5
1 2 3 4 5
*/
