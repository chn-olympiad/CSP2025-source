#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=300;
ll t,a[N][4],n,ma;
bool f;
namespace one{
	void solve(){
		sort(a[1]+1,a[1]+4), sort(a[2]+1,a[2]+4);
		cout<<max(a[1][3]+a[2][2],a[1][2]+a[2][3])<<'\n';
	}
}
namespace two_to_eleven{
	ll dp[N][N][N];
	void solve(){ma=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i+j+k>n) break;
					dp[i][j][k]=max((i>0)*(dp[i-1][j][k]+a[i+j+k][1]),max((j>0)*(dp[i][j-1][k]+a[i+j+k][2]),(k>0)*(dp[i][j][k-1]+a[i+j+k][3])));
					ma=max(ma,dp[i][j][k]);
				}
			}
		}cout<<ma<<'\n';
	}
}
namespace twelve{
	ll b[N],sl;
	void solve(){
		for(int i=1;i<=n;i++) b[i]=a[i][1];
		sort(b+1,b+n+1);
		for(int i=n/2+1;i<=n;i++) sl+=b[i];
		cout<<sl<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n, f=1;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++) if(a[i][2]||a[i][3]) f=0;
		if(n==2) one::solve();
		else if(n<=300) two_to_eleven::solve();
		else if(f) twelve::solve();
	}
	return 0;
}
