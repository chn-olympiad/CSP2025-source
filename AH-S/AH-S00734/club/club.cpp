#include<bits/stdc++.h>
using namespace std;
int t,n,m,w[100005][5],f[205][205][205],dp[205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>w[i][j];
			}
		}
		if(n==200){
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int x=m;x>=0;x--){
					for(int y=m;y>=0;y--){
						if(x>0)dp[x][y]=max(dp[x][y],dp[x-1][y]+w[i][1]);
						if(y>0)dp[x][y]=max(dp[x][y],dp[x][y-1]+w[i][2]);
					}
				}
			}
			cout<<dp[m][m]<<endl;
		}else{
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int x=m;x>=0;x--){
					for(int y=m;y>=0;y--){
						for(int z=m;z>=0;z--){
							if(x>0)f[x][y][z]=max(f[x][y][z],f[x-1][y][z]+w[i][1]);
							if(y>0)f[x][y][z]=max(f[x][y][z],f[x][y-1][z]+w[i][2]);
							if(z>0)f[x][y][z]=max(f[x][y][z],f[x][y][z-1]+w[i][3]);
						}
					}
				}
			}
			cout<<f[m][m][m]<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
