#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
long long zong[111111][3];
int num[111111][3][3],a[111111][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>zong[i][0]>>zong[i][1]>>zong[i][2];
			num[i][0][1]=0;
			num[i][1][1]=0;
			num[i][2][1]=0;
			num[i][0][0]=0;
			num[i][1][0]=0;
			num[i][2][0]=0;
			num[i][0][2]=0;
			num[i][1][2]=0;
			num[i][2][2]=0;
			
		}
		//cout<<n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(zong[i][j]+zong[i-1][k]>zong[i][j]&&num[i-1][k][j]+1<=n/2){
						zong[i][j]=max(zong[i][j]+zong[i-1][k],zong[i][j]);
						num[i][j][j]=num[i-1][k][j]+1;
						num[i][j][(j+1)%3]=num[i-1][k][(j+1)%3]+1;
						num[i][j][(j+2)%3]=num[i-1][k][(j+2)%3]+1;
					}
				}
				ans=max(ans,zong[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
