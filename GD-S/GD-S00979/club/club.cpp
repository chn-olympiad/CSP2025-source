#include<bits/stdc++.h>
using namespace std;
const int N = 3e2+10;
const int M = 1e5+10;
long long t,n,a[M][10],dp[N][N][N];
struct node{
	long long v,id;
}A[M];
bool cmp(node a,node b){
	return a.v>b.v;
}
void solve2(){
	int f1=1,f2=1,f3=1;
	for(int i = 1; i <= n; i++){
		if(a[i][3]!=0){
			f2=0;f1=0;
		} 
		if(a[i][2]!=0){
			f1=0;
		}
		A[i].v=a[i][1];
		A[i].id=i;
	}
	if(f1){
		long long ans=0;
		sort(A+1,A+n+1,cmp);
		for(int i = 1; i <= n/2; i++){
			ans+=A[i].v;
		}
		cout << ans << endl;
		return;
	}
//	if(f2){
//		
//	} 
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	if(n>200){
		solve2();return;
	}
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = n/2; j >= 0; j--){
			for(int k = n/2; k >= 0; k--){
				for(int l = min(n/2,n-j-k); l >= 0; l--){
					if(j>=1)dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][1]);
					if(k>=1)dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i][2]);
					if(l>=1)dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][3]);
				}
			}
		}
	}
	long long ans=0;
	for(int j = n/2; j >= 0; j--){
		for(int k = n/2; k >= 0; k--){
			if(j+k<=n&&n/2>=n-j-k&&n-j-k>=0){
				ans=max(ans,dp[j][k][n-j-k]);
			}
		}
	}
	cout << ans << endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){solve();}
	return 0;
} 
