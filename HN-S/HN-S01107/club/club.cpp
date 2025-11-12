#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
int dp[205][205][205];
int dpB[100005][10];
bool A=1,B=1,C=1;
int ans;
bool cmp(int x,int y){
	return x>y;
}
void solveA(){
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;++i){
		ans+=a[i];
	}
	cout<<ans<<endl;
	return;
}
void solveB(){
//	cout<<"BBBB"<<endl;
	for(int i=0;i<=n;++i)dpB[i][0]=dpB[i][1]=0;
	int f=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=min(i,n/2);++j){
			if(i-j>n/2)continue;
			if(i-j>0)dpB[j][f]=dpB[j][f^1]+b[i];
			if(j>0)dpB[j][f]=max(dpB[j][f],dpB[j-1][f^1]+a[i]);
			ans=max(dpB[j][f],ans);
		}
		f=f^1;
	}cout<<ans<<endl;
	return;
}
void solve(){
	cin>>n;
	ans=0;
	A=1,B=1,C=1;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0)A=0;
		if(c[i]!=0)A=0,B=0;
	}
	if(A){
		solveA();
		return;
	}
	if(B){
		solveB();
		return;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=min(i,n/2);++j){
			for(int k=0;k<=min(i-j,n/2);++k){
				if(i-j-k>n/2)continue;
				if(j>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+a[i]);
				if(k>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+b[i]);
				if(i-j-k>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+c[i]);
				ans=max(ans,dp[j][k][i-j-k]);
			}
		}
	}
	for(int i=0;i<=n/2;++i){
		for(int j=0;j<=n/2;++j){
			for(int k=0;k<=n/2;++k){
				dp[i][j][k]=0;
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1

