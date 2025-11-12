#include<bits/stdc++.h>
using namespace std;
using int64=long long;
bool _debug=false;
constexpr int maxN=205;
int n,T,a[maxN][5],max_ans,dp[maxN][maxN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if(!_debug) {
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	}
	cin>>T;
	for(int h=1; h<=T; h++) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
				
			}
		}
		for(int j=n/2; j>=0; j--) {
			for(int k=n/2; k>=0; k--) {
				dp[j][k]=INT_MIN+1145;
			}
		}
		dp[0][0]=0;
		for(int i=1; i<=n; i++) {
			for(int j=min(n/2,i); j>=0; j--) {
				for(int k=min(n/2,i-j); k>=0&&(j+k)>=i-(n/2);k--) {
					int dpjk=INT_MIN; 
					if(j-1>=0)
						dpjk=max(dpjk,dp[j-1][k]+a[i][1]);
					if(k-1>=0)
						dpjk=max(dpjk,dp[j][k-1]+a[i][2]);
					if(j+k<=i-1)
						dpjk=max(dpjk,dp[j][k]+a[i][3]);
//					cout<<j<<' '<<k<<dp[j][k]<<'\n';
					dp[j][k]=dpjk;
				}
			}
		}
		max_ans=INT_MIN;
		for(int j=n/2; j>=0; j--) {
			for(int k=n/2; k>=0; k--) {
				max_ans=max(max_ans,dp[j][k]);
			}
		}
		cout<<max_ans<<'\n';
	}

	return 0;
}
