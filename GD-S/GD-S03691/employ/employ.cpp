#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
string s;
int n,m;
int a[505];
long long dp[1005][1005];
//void init(){
//	for(int i=1;i<=1000;i++){
//		dp[i][0] = 1;
//		dp[i][i] = 1;
//		for(int j=1;j<i;j++){
//			dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%M;
//		}
//	}
//}
long long get(int l,int r){
//	cout << l << r << endl;
	long long res = 1;
	for(long long i=l;i<=r;i++) res = (res*i)%M;
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
//	init();
	long long ans = 0;
//	cin >> n >> m;
//	cin >> s;
//	for(int i=1;i<=n;i++) cin >> a[i];
	n = 100;m = 47;
	for(int i=m;i<=n;i++){
		cout << i << endl;
		ans = (ans+get(n-m+1,n))%M; 
	}
	cout << ans;
//	fclose(stdin);
//	fclose(stdout);
}
