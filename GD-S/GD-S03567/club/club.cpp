#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 205;
int n,t,ans,dp[M][M][M];
struct node{
	int a[5],id;
}s[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		ans = INT_MIN;
		cin>>n;
		for(int i = 1; i<=n; i++){
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
		}
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<=i; j++){
				for(int p = 0; p+j<=i; p++){
					if(j>n/2 || p>n/2 || i-j-p>n/2) continue;
//					cout<<j<<" "<<p<<endl;
					dp[i][j][p] = max((dp[i-1][j-1][p]+s[i].a[1])*(j!=0),max((dp[i-1][j][p-1]+s[i].a[2])*(p!=0),(dp[i-1][j][p]+s[i].a[3])*(i-j-p!=0)));
//					cout<<dp[i-1][j-1][p]+s[i].a[1]<<" "<<dp[i-1][j][p-1]+s[i].a[2]<<" "<<dp[i-1][j][p]+s[i].a[3]<<endl;
				}
			}
		}
		for(int j = 0; j<=n; j++){
			for(int p = 0; p+j<=n; p++){
				if(j>n/2 || p>n/2 || n-j-p>n/2) continue;
				ans = max(ans,dp[n][j][p]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
