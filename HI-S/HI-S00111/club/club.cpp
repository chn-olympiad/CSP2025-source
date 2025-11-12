#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[100100][4],dp1[210][110][110],dp2[51000],ans;
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						dp1[i][j][k]=0;
						if(i-j-k>n/2){
							continue;
						}
						if(j){
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j-1][k]+a[i][1]);
						}
						if(k){
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k-1]+a[i][2]);
						}
						if(i-j-k){
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k]+a[i][3]);
						}
						ans=max(ans,dp1[i][j][k]);
					}
				}
			}
		}
		else{
			for(int i=0;i<=n/2;i++){
				dp2[i]=0;
			}
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					if(i-j>n/2){
						//cout<<i<<' '<<j<<endl;
						break;
					}
					if(!(i-j)){
						dp2[j]=0;
					}
					else{
						dp2[j]+=a[i][1];
					}
					if(j){
						dp2[j]=max(dp2[j],dp2[j-1]+a[i][2]);
					}
					ans=max(ans,dp2[j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


