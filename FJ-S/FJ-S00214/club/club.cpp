#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int f[103][103][203],a[N][5],n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin >>T;
	while(T--){
		cin >>n;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin >>a[i][j];
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				for(int k=1;k<=n;k++){
					f[i][j][k]=max({f[i-1][j][k-1]+a[k][0],f[i][j-1][k-1]+a[k][1],f[i][j][k-1]+a[k][2]});
				}
			}
		}
		int ans=-114514;
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<=n/2;j++)ans=max(f[i][j][n],ans);
		cout <<ans;
	}
	return 0;
}
