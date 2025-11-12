#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n;
const int maxn = 1e5 + 10;
ll a[maxn][5];
ll dp_pts[210][110][110];
ll b[maxn];
//
bool isA(){
	for(int i=1;i<=n;i++){
		if(a[i][2] || a[i][3]) return false;
	}
	return true;
}
bool isB(){
	for(int i=1;i<=n;i++){
		if(a[i][3]) return false;
	}
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n <= 200){
			for(int x=0;x<=n;x++){
				for(int i=0;i<=n/2;i++){
					for(int j=0;j<=n/2;j++){
						dp_pts[x][i][j] = -1e18;
					}
				}
			}
			dp_pts[0][0][0] = 0;
			for(int x=1;x<=n;x++){
				for(int i=0;i<=n/2;i++){
					for(int j=0;j<=n/2;j++){
						int k = x - i - j;
						if(k < 0) continue;
						if(k > n/2) continue;
						dp_pts[x][i][j] = max({(i?dp_pts[x-1][i-1][j]:(ll)-1e18) + a[x][1],(j?dp_pts[x-1][i][j-1]:(ll)-1e18) + a[x][2],(k?dp_pts[x-1][i][j]:(ll)-1e18) + a[x][3]});
					}
				}
			}
			ll ans = 0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(n-i-j < 0) continue;
					if(n-i-j > n/2) continue;
					ans = max(ans,dp_pts[n][i][j]);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(isA()){
			for(int i=1;i<=n;i++) b[i] = a[i][1];
			sort(b+1,b+n+1);
			ll ans = 0;
			for(int i=n/2+1;i<=n;i++){
				ans += b[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		if(isB()){
			ll ans = 0;
			for(int i=1;i<=n;i++) ans += a[i][1];
			for(int i=1;i<=n;i++){
				b[i] = a[i][2] - a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n/2+1;i<=n;i++) ans += b[i];
			cout<<ans<<'\n';
			continue;
		} 
	}
	return 0;
}
