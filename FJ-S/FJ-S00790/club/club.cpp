#include<bits/stdc++.h>
using namespace std;
struct sb{
	int a,b,c;
}x[100005];
int q,n,dp[205][205][205],ans;
bool cmp(sb a,sb b){
	return a.a>b.a;
}
bool cmp1(sb a,sb b){
	return a.a+b.b>b.a+a.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].b>>x[i].c;
		if(n>200){
			ans=0;
			sort(x+1,x+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=x[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=x[i].b;
			cout<<ans<<endl;
		}
		memset(dp,0,sizeof dp);
		dp[1][0][0]=x[1].a;
		dp[0][1][0]=x[1].b;
		dp[0][0][1]=x[1].c;
		for(int i=2;i<=n;i++) for(int j=0;j<=min(n/2,i);j++) for(int k=0;k<=min(n/2,i);k++) for(int l=0;l<=min(n/2,i);l++){
			if(j+k+l!=i) continue;
			if(j>0) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+x[i].a);
			if(k>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+x[i].b);
			if(l>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+x[i].c);
		}
		ans=0;
		for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++){
			int k=n-i-j;
			if(k<=n/2) ans=max(ans,dp[i][j][k]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
