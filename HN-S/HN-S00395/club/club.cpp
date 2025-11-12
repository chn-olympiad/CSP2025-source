#include<bits/stdc++.h>
using namespace std;
const int N = 1100;
int a[N][5];
long long f[N][N],V[5];
void solve(){
	memset(f,0,sizeof(f));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	long long ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>=0;j--){
			for(int k = n/2;k>=0;k--){
				if(j + k > i)continue;
				if(i - j - k>0 && i - j - k <= n/2){
					f[j][k] = max(f[j][k],f[j][k] + a[i][3]);
				}
				if(j>0){
					f[j][k] = max(f[j][k],f[j-1][k] + a[i][1]);
				}
				if(k>0){
					f[j][k] = max(f[j][k],f[j][k-1] + a[i][2]);
				}
//				cout<<i<<" "<<j<<" "<<k<<" "<<i - j - k<<" "<<f[j][k]<<endl;
				if(j <= n/2 && k<=n/2 && i - j - k <= n/2){
					ans = max(ans,f[j][k]);
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//freopen
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
