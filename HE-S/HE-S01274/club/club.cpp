#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n;
int a[N][4],f[N],dp[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int maxn = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			int maxn = 0;
			for(int i = 1;i<=3;i++){
				for(int j = 1;j<=3 && j!=i;j++){
					maxn = max(maxn,a[1][i]+a[2][j]);
				}
			}
			cout<<maxn;
			return 0;
		}
		for(int i = 1;i<=n;i++){
			f[i] = a[1][i];
			dp[i] = a[2][i];
		}
		sort(f+1,f+n+1);
		sort(dp+1,dp+n+1);
		for(int i = n;i>n/2;i--){
			maxn+=dp[i];
		}
		for(int i = n;i>n/2;i--){
			maxn+=f[i];
		}
		cout<<maxn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
