#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=15;
const int maxm=15;
int dp[maxn][maxm],a[maxn*maxm],ans,z,n,m;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ans=a[1];
	for(int i=1;i<n*m;i++)
		for(int j=i+1;j<=n*m;j++)
			if(a[i]<a[j])swap(a[i],a[j]);
	for(int i=1;i<=n;i++){
		if(i%2==1)
			for(int j=1;j<=m;j++){
				dp[i][j]=a[++z];
				if(a[z]==ans){
					cout<<i<<" "<<j;
					return;
				}
			}
		else
			for(int j=m;j>=1;j--){
				dp[i][j]=a[++z];
				if(a[z]==ans){
					cout<<i<<" "<<j;
					return;
				}
			}
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
	return 0;
}
