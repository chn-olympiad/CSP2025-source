#include<bits/stdc++.h>
using namespace std;
const int N=10005;
long int a[N][N],dp[N][N],n,l[5],t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%ld",&t);
	while(t--){
		scanf("%ld",&n);
		if(n==0){
			cout << 0;
			break;
		}
		for(long int i=1;i<=n;i++){
			for(long int j=1;j<=3;j++){
				cin >> a[i][j];
				dp[i][j] = 0;
				l[j] = 0;
			}
		}
		for(long int i=1;i<=n;i++){
			for(long int j=1;j<=3;j++){
				dp[i][j] = max({dp[i-1][1]+a[i][j],dp[i-1][2]+a[i][j],dp[i-1][3]+a[i][j]});
			}
		} 
		printf("%ld\n",max({dp[n][1],dp[n][2],dp[n][3]}));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
