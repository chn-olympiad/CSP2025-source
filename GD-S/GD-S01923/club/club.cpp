#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n;
struct node{
	int a,b,c,sum;
}dp[N][5],a[N];
bool cmp(node x,node y){
	return x.a+x.b+x.c > y.a+y.b+y.c;
}void solve(){
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i].a >> a[i].b>>a[i].c;
	for(int i=1;i<=n;i++){
		dp[i][1].a = dp[i][1].b = dp[i][1].c = dp[i][1].sum = 0;
		dp[i][2].a = dp[i][2].b = dp[i][2].c = dp[i][2].sum = 0;
		dp[i][3].a = dp[i][3].b = dp[i][3].c = dp[i][3].sum = 0;
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(dp[i-1][j].a<n/2){
				if(dp[i][1].sum<=dp[i-1][j].sum+a[i].a){
					dp[i][1].sum = dp[i-1][j].sum+a[i].a;
					dp[i][1].a=dp[i-1][j].a+1,dp[i][1].b=dp[i-1][j].b,dp[i][1].c=dp[i-1][j].c;
				}
			}if(dp[i-1][j].b<n/2){
				if(dp[i][2].sum<=dp[i-1][j].sum+a[i].b){
					dp[i][2].sum = dp[i-1][j].sum+a[i].b;
					dp[i][2].a=dp[i-1][j].a,dp[i][2].b=dp[i-1][j].b+1,dp[i][2].c=dp[i-1][j].c;
				}
			}if(dp[i-1][j].c<n/2){
				if(dp[i][3].sum<=dp[i-1][j].sum+a[i].c) {
					dp[i][3].sum =dp[i-1][j].sum+a[i].c;
					dp[i][3].a=dp[i-1][j].a , dp[i][3].b=dp[i-1][j].b , dp[i][3].c=dp[i-1][j].c+1;
				}
			}
		}/*
		for(int j=1;j<=3;j++){
			cout << dp[i][j].a << " "<<dp[i][j].b << " "<<dp[i][j].c << " "<<dp[i][j].sum<<endl;
		}*/
	}cout << max({dp[n][1].sum,dp[n][2].sum,dp[n][3].sum})<<endl;
	return ;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
