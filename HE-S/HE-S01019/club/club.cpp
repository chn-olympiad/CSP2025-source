#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],k,opx[100005],opy[100005],opz[100005],ms=0;
	long long dp[100005];
	int findx(){
		for(int i=1;i<=n;i++){
			if(opx[i]){
				if(a[i][2]-a[i][1]>=ms){
					ms=a[i][2]-a[i][1];
				k=i;
			}
			if(a[i][3]-a[i][1]>=ms){
				ms=a[i][3]-a[i][1];
				k=i;
			}
			}
		}
		return k;
	}
		int findy(){
		for(int i=1;i<=n;i++){
			if(opy[i]){
				if(a[i][1]-a[i][2]>=ms){
					ms=a[i][1]-a[i][2];
				k=i;
			}
			if(a[i][3]-a[i][2]>=ms){
				ms=a[i][3]-a[i][2];
				k=i;
			}
			}
		}
		return k;
	}
		int findz(){
		for(int i=1;i<=n;i++){
			if(opz[i]){
				if(a[i][2]-a[i][3]>=ms){
					ms=a[i][2]-a[i][3];
				k=i;
			}
			if(a[i][1]-a[i][3]>=ms){
				ms=a[i][1]-a[i][3];
				k=i;
			}
			}
		}
		return k;
	}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
	    dp[0]=0;
		int x=0,y=0,z=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
			opx[i]=0;
			opy[i]=0;
			opz[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(x<n/2 && y<n/2 && z<n/2){
				dp[i]=max(dp[i-1]+a[i][1],max(dp[i-1]+a[i][2],dp[i-1]+a[i][3]));
				if(dp[i]==dp[i-1]+a[i][1]){
					x++;
					opx[i]=1;
				}else if(dp[i]==dp[i-1]+a[i][2]){
					y++;
					opy[i]=1;
				}else{
					z++;
					opz[i]=1;
				}
				continue;
			}
			k=0;
			ms=-500000;
			if(x==n/2){
				k=findx();
				dp[i]=max(dp[i-1]+a[i][2],dp[i-1]+a[i][3]);
				dp[i]=max(dp[i],dp[i-1]+a[i][1]-a[k][1]+a[k][2]);
				dp[i]=max(dp[i],dp[i-1]+a[i][1]-a[k][1]+a[k][3]);
				if(dp[i]>dp[i-1]+a[i][2] && dp[i]>dp[i-1]+a[i][3]){
					opx[k]=0;
					opx[i]=1;
					if(a[k][2]>a[k][3]){
						y++;
						opy[k]=1;
					}else{
						z++;
						opz[k]=1;
					}
				}
				continue;
			}
			if(y==n/2){
				k=findy();
				dp[i]=max(dp[i-1]+a[i][1],dp[i-1]+a[i][3]);
				dp[i]=max(dp[i],dp[i-1]+a[i][2]-a[k][2]+a[k][1]);
				dp[i]=max(dp[i],dp[i-1]+a[i][2]-a[k][2]+a[k][3]);
				if(dp[i]>dp[i-1]+a[i][1] && dp[i]>dp[i-1]+a[i][3]){
					opy[k]=0;
					opy[i]=1;
					if(a[k][1]>a[k][3]){
						x++;
						opx[k]=1;
					}else{
						z++;
						opz[k]=1;
					}
				}
				continue;
			}
			if(z==n/2){
				k=findz();
				dp[i]=max(dp[i-1]+a[i][1],dp[i-1]+a[i][2]);
				dp[i]=max(dp[i],dp[i-1]+a[i][3]-a[k][3]+a[k][1]);
				dp[i]=max(dp[i],dp[i-1]+a[i][3]-a[k][3]+a[k][2]);
				if(dp[i]>dp[i-1]+a[i][1] && dp[i]>dp[i-1]+a[i][2]){
					opz[k]=0;
					opz[i]=1;
					if(a[k][1]>a[k][2]){
						x++;
						opx[k]=1;
					}else{
						y++;
						opy[k]=1;
					}
				}
				continue;
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}
