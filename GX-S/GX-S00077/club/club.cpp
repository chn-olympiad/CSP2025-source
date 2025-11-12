#include<bits/stdc++.h>
using namespace std;
long long a[15][100010],b[15][100010],c[15][100010];
long long t,dp[15][100010],r1[15],r2[15],r3[15];
queue<int>q;
long long maxx(long long a,long long b,long long c){
	if(a>b){
		if(a>c){
			return a;
		}else{
			return c;
		}
	}else{
		if(b>c){
			return b;
		}else{
			return c;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=0;i<t;i++){
		int n;
		cin>>n;
		for(long long j=n-1;j>=0;j--){
			cin>>a[i][j]>>b[i][j]>>c[i][j];
		}for(long long j=1;j<=n;j++){
			int h;
			for(long long k=0;k<j;k++){
				if(r1[i]>=n/2){
					dp[i][j]=max(dp[i][k]+b[i][k],dp[i][k]+c[i][k]);
					if(dp[i][j]-dp[i][k]==b[i][k]){
						h=2;
					}else{
						h=3;
					}
				}else if(r2[i]>=n/2){
					dp[i][j]=max(dp[i][k]+a[i][k],dp[i][k]+c[i][k]);
					if(dp[i][j]-dp[i][k]==a[i][k]){
						h=1;
					}else{
						h=3;
					}
				}else if(r3[i]>=n/2){
					dp[i][j]=max(dp[i][k]+a[i][k],dp[i][k]+b[i][k]);
					if(dp[i][j]-dp[i][k]==a[i][k]){
						h=1;
					}else{
						h=2;
					}
				}else{
					dp[i][j]=maxx(dp[i][k]+a[i][k],dp[i][k]+b[i][k],dp[i][k]+c[i][k]);
					if(dp[i][j]-dp[i][k]==a[i][k]){
						h=1;
					}else if(dp[i][j]-dp[i][k]==b[i][k]){
						h=2;
					}else{
						h=3;
					}
				}
			}if(h==1){
				r1[i]++;
			}else if(h==2){
				r2[i]++;
			}else{
				r3[i]++;
			}
			/*if(r1[i]>=n/2){
				dp[i][j]=max(dp[i][j-1]+b[i][j-1],dp[i][j-1]+c[i][j-1]);
				if(dp[i][j]-dp[i][j-1]==b[i][j-1]){
					r2[i]++;
				}else{
					r3[i]++;
				}
			}else if(r2[i]>=n/2){
				dp[i][j]=max(dp[i][j-1]+a[i][j-1],dp[i][j-1]+c[i][j-1]);
				if(dp[i][j]-dp[i][j-1]==a[i][j-1]){
					r1[i]++;
				}else{
					r3[i]++;
				}
			}else if(r3[i]>=n/2){
				dp[i][j]=max(dp[i][j-1]+a[i][j-1],dp[i][j-1]+b[i][j-1]);
				if(dp[i][j]-dp[i][j-1]==a[i][j-1]){
					r1[i]++;
				}else{
					r2[i]++;
				}
			}else{
				dp[i][j]=maxx(dp[i][j-1]+a[i][j-1],dp[i][j-1]+b[i][j-1],dp[i][j-1]+c[i][j-1]);
				if(dp[i][j]-dp[i][j-1]==a[i][j-1]){
					r1[i]++;
				}else if(dp[i][j]-dp[i][j-1]==b[i][j-1]){
					r2[i]++;
				}else{
					r3[i]++;
				}
			}cout<<r1[i]<<" "<<r2[i]<<" "<<r3[i]<<" "<<dp[i][j]<<" ";*/
		}cout<<dp[i][n]<<endl;
	}
	return 0;
}
