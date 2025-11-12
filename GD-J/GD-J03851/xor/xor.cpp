/*
1.亦或固定值高效处理
2.查询最值 
*/
#include <bits/stdc++.h>
using namespace std;
//const int N=5e5+5;
const int N=1e3+5;
int n,k;
int a[N];
int dp[N]; 
int p[N][N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		p[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			p[i][j]=p[i][j-1]^a[j];
		}
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(p[j][i]==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
