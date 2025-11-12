#include <bits/stdc++.h>
using namespace std;
const int N=5005,V=10001,mod=998244353;
int dp[10010][2],n,a[N],ans,ret;
void Add(int &x,int y){
	x=x+y>=mod?x+y-mod:x+y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=V;j>=0;j--){
			Add(dp[min(V,j+a[i])][1],(dp[j][1]+dp[j][0])%mod);
		}
		if(a[i]!=a[i+1]){
			for(int j=0;j<=V;j++) Add(ans,dp[j][1]*(j>2*a[i])),Add(dp[j][0],dp[j][1]),dp[j][1]=0;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

