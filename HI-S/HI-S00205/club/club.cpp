#include <bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],dp[100001][3],b,c,d,maxn;
void maxnn(){
	int maxxn=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			if(maxxn<=dp[i][j]){
				maxxn=dp[i][j];
			}
		}
	}
	cout<<maxxn<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		n=0,b=0,c=0,d=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		int zoo=0;
		for(int i=0;i<n;i++){
			if(a[i][1]==0&&a[i][2]==0){
				int x=a[i][0],y=a[i][1],z=a[i][2];
				a[i][0]=a[zoo][0];
				a[i][1]=a[zoo][1];
				a[i][2]=a[zoo][2];
				a[zoo][0]=x;
				a[zoo][1]=y;
				a[zoo][2]=z;
				zoo++;
			}
		}
		maxn=n/2;
		dp[0][0]=a[0][0];
		dp[0][1]=a[0][1];
		dp[0][2]=a[0][2];
		for(int i=1;i<n;i++){
			int maxx;
			if(dp[i-1][0]>=dp[i-1][1]&&dp[i-1][0]>=dp[i-1][2]){
				if(b<maxn){
					maxx=dp[i-1][0];
					b++;
				}else{
					if(dp[i-1][1]>=dp[i-1][2]){
						maxx=dp[i-1][1];
					}else{
						maxx=dp[i-1][2];
					}
				}
			}else if(dp[i-1][1]>=dp[i-1][0]&&dp[i-1][1]>=dp[i-1][2]){
				if(c<maxn){
					maxx=dp[i-1][1];
					c++;
				}else{
					if(dp[i-1][0]>=dp[i-1][2]){
						maxx=dp[i-1][0];
					}else{
						maxx=dp[i-1][2];
					}
				}
			}else if(dp[i-1][2]>=dp[i-1][1]&&dp[i-1][2]>=dp[i-1][0]){
				if(d<maxn){
					maxx=dp[i-1][2];
					d++;
				}else{
					if(dp[i-1][1]>=dp[i-1][0]){
						maxx=dp[i-1][1];
					}else{
						maxx=dp[i-1][0];
					}
				}
			}
			for(int j=0;j<3;j++){
				if(n==2&&((j==0&&b==maxn)||(j==1&&c==maxn)||(j==2&&d==maxn))) continue;
				else dp[i][j]=a[i][j]+maxx;
			}
		}
		maxnn();
	}
	return 0;
}
