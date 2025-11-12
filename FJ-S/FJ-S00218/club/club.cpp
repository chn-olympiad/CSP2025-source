#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int t,n,a[N][4],f[102][102][102];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int l=n/2;l>=0;l--){
						if(j!=0){
							if(f[j][k][l]<f[j-1][k][l]+a[i][1]){
								f[j][k][l]=f[j-1][k][l]+a[i][1];
							}
						}
						if(k!=0){
							if(f[j][k][l]<f[j][k-1][l]+a[i][2]){
								f[j][k][l]=f[j][k-1][l]+a[i][2];
							}
						}
						if(l!=0){
							if(f[j][k][l]<f[j][k][l-1]+a[i][3]){
								f[j][k][l]=f[j][k][l-1]+a[i][3];
							}
						}
					}
				}
			}
		}
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n-j && k<=n/2;k++){
				for(int l=0;l<=n-j-k && l<=n/2;l++){
					if(f[j][k][l]>ans){
						ans=f[j][k][l];
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
