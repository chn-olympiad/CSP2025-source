#include <bits/stdc++.h>

using namespace std;
int n,a[100005][4],t,dp[100005];

void so(int c){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(a[j-1][c]>a[j][c]){
				for(int k=1;k<=3;k++){
				int t=a[j-1][k];
				a[j-1][k]=a[j][k];
				a[j][k]=t;
			    }
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		long long k1[4]={0,0,0,0};
		for(int i=1;i<=n;i++) dp[i]=0;
		/*for(int i=1;i<=n;i++){
			dp[i][0]=0;
			dp[0][i]=0;
		}*/
		/*for(int j=1;j<=i;j++){
			long long a1=-1,a2=-1,a3=-1;
			if(k1<=(n/2)) a1=max(dp[i][j-1]+a[i][1],dp[i-1][j]);
			if(k2<=(n/2)) a2=max(dp[i][j-1]+a[i][2],dp[i-1][j]);
			if(k3<=(n/2)) a3=max(dp[i][j-1]+a[i][3],dp[i-1][j]);
			if(a1==-1&&a2==-1&&a3==-1) break;
			long long aa=max(a1,a2);
			dp[i][j]=max(aa,a3);
			if(dp[i][j]==k1){
				k1++;
			}else if(dp[i][j]==k2){
				k2++;
			}else if(dp[i][j]==k3){
				k3++;
			}
		}
	}*/
			for(int j=1;j<=n;j++){
				long long a1[4]={-1,-1,-1,-1};
				for(int k=1;k<=3;k++){
					if(k1[k]<=n/2){
					   so(k);
					   dp[j]=max(dp[j],dp[j-1]+a[j][k]);
					   a1[k]==dp[j];
				    }
				}
				if(dp[j]==a1[1]){
				    k1[1]++;
			    }else if(dp[j]==a1[2]){
				    k1[2]++;
			    }else if(dp[j]==a1[3]){
				    k1[3]++;
			    }
		    }
			}
			
	cout<<dp[n]<<endl;
	}
	return 0;
}

