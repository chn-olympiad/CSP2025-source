#include<bits/stdc++.h>
using namespace std;
int dp[205][205][3],ip[100005],n,ma,T,a[100005],b[100005],c[100000];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
while(T--){
	ma=0;
	int flag1=1,flag2=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0)flag1=0;
		if(c[i]!=0)flag2=0;
	}
	if(flag1&&n>200){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ma+=a[i];
		}
		cout<<ma<<"\n";
		continue;
	}
	if(flag2){
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				if(j!=0)ip[j]=max(ip[j],ip[j-1]+a[i]);
				if(n-j<=n/2)ip[j]=max(ip[j],ip[j]+b[i]);
				ma=max(ma,ip[j]);
			}
		}
		cout<<ma<<"\n";
		for(int i=1;i<=n;i++){
			ip[i]=0;
		}
		continue;
	}
	for(int i=1;i<=n;i++){
		int x=a[i],y=b[i],z=c[i];
		for(int j=0;j<=i;j++){
			for(int k=0;k+j<=i;k++){
				dp[j][k][i&1]=0;
				if(j!=0)dp[j][k][i&1]=max(dp[j][k][i&1],dp[j-1][k][(i-1)&1]+x);
				if(k!=0)dp[j][k][i&1]=max(dp[j][k][i&1],dp[j][k-1][(i-1)&1]+y);
				if(k+j!=i)dp[j][k][i&1]=max(dp[j][k][i&1],dp[j][k][(i-1)&1]+z);
				//dp[j][k][i&1]=max({dp[j][k-1][(i-1)&1]+y,dp[j-1][k][(i-1)&1]+x,dp[j][k][(i-1)&1]+z});
				
				if(j<=n/2&&k<=n/2&&j+k>=n/2){
					//cout<<i<<" "<<j<<" "<<k<<" "<<dp[j][k][i&1]<<"\n";
					ma=max(ma,dp[j][k][i&1]);
				} 
			}
		}
	}
	for(int j=0;j<=n;j++){
		for(int k=0;k+j<=n;k++){
			dp[j][k][1]=dp[j][k][0]=0;
		}
	}cout<<ma<<"\n";
}
	
	
	return 0;
} 
/*
k<i-j
*/
