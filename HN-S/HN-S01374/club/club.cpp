#include<bits/stdc++.h>

using namespace std;
//Ren5Jie4Di4Ling5%

long long t,n,a[100010][10],dp[202][101][101],b[100010],id=0;
vector<long long>c[3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=200){
			memset(dp,0,sizeof dp);
			for(long long i=1;i<=n;i++)for(long long j=1;j<=3;j++)cin>>a[i][j];
			long long mx=0;
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n/2;j++){
					for(long long k=1;k<=n/2;k++){
						dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],max(dp[i-1][j][k-1]+a[i][2],dp[i-1][j][k]+a[i][3]));
						if(i==n)mx=max(mx,dp[i][j][k]);
					}
				}
			}
			cout<<mx<<"\n";
		
		}
		else{
			long long f=1,ff=1;
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=3;j++){
					cin>>a[i][j];
					if(j==2||j==3)f&=(a[i][j]==0);
					if(j==3)ff&=(a[i][j]==0);
				}
			}
			if(f){
				id=0;
				for(long long i=1;i<=n;i++){
					b[++id]=a[i][1];
				}
				sort(b+1,b+1+n);
				long long su=0;
				for(long long i=n/2+1;i<=n;i++)su+=b[i];
				cout<<su<<"\n";
			}
			else {
				long long su=0;
				for(long long i=1;i<=n;i++){
					long long mx=0;
				for(long long j=1;j<=3;j++){
					mx=max(mx,a[i][j]);
				}
				su+=mx;
			}
			}
		}
	
	}
	return 0;
} 
/*
1
4
5 1 1
5 0 0 
5 3 3
1 1 1

1
4
1 0 0
0 0 0
6 0 0
5 0 0
*/
