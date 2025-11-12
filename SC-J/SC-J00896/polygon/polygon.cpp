#include<bits/stdc++.h>
using namespace std;

const int NM = 5e3,mod = 998244353;
int mk[NM+4][NM+4],G[NM+4],A[NM+4],dp[NM+4];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i = 1;i <= n;i++) cin>>A[i],G[i] = G[i-1]+A[i];
	for(int i = 1;i <= n;i++)
		for(int j = i;j <= n;j++)
			mk[i][j] = max(mk[i][j-1],A[j]);
	if(G[n] == n){
		for(int i = 1;i <= n;i++) ans = (ans+(n-i)*(n-i-1)/2)%mod;
		cout<<ans;
		return 0;
	}
	for(int i = 1;i <= n;i++){//大左 
		for(int j = i+2;j <= n;j++){//大右 
			ans = (ans+(G[j]-G[i-1]>2*mk[i][j]))%mod;
//			if(G[j]-G[i-1]>2*mk[i][j]) cout<<i<<' '<<j<<'\n';
			for(int x = i+1;x < j;x++){//删左 
				for(int y = x;y < j;y++){//删右 
					if(j-i+1-(y-x+1) >= 3) ans = (ans+(G[j]-G[y]+G[x-1]-G[i-1]>2*max(mk[y+1][j],mk[i][x-1])))%mod;
//					if(j-i+1-(y-x+1) >= 3 and G[j]-G[y]+G[x-1]-G[i-1]>2*max(mk[y+1][j],mk[i][x-1]))
//						cout<<i<<' '<<x<<' '<<y<<' '<<j<<'\n';
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
