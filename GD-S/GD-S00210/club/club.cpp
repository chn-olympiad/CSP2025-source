#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][5];
int dp[205][205][205];
void solve1(){
	int Max=(n>>1);
	for(int i=1;i<=n;++i)
		for(int t1=0;t1<=Max;++t1)
			for(int t2=0;t2<=Max;++t2){
				int t3=i-t1-t2;
				if(t3<0) break;
				if(t3>Max) continue;
				dp[i][t1][t2]=0;
				if(t1>0) dp[i][t1][t2]=max(dp[i][t1][t2],dp[i-1][t1-1][t2]+a[i][1]);
				if(t2>0) dp[i][t1][t2]=max(dp[i][t1][t2],dp[i-1][t1][t2-1]+a[i][2]);
				if(t3>0) dp[i][t1][t2]=max(dp[i][t1][t2],dp[i-1][t1][t2]+a[i][3]);
			}
	int ans=0;
	for(int t1=0;t1<=Max;++t1)
		for(int t2=0;t2<=Max;++t2)
			ans=max(ans,dp[n][t1][t2]);
	cout<<ans<<'\n';
}
int aa[100005];
void solve2(){
	for(int i=1;i<=n;++i)
		aa[i]=a[i][1];
	stable_sort(aa+1,aa+n+1,greater<int>());
	int Max=(n>>1);
	int ans=0;
	for(int i=1;i<=Max;++i)
		ans+=aa[i];
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool A=true;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) A=false;
		}
		if(n<=200){
			solve1();
			continue;
		}
		if(A){
			solve2();
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i)
			ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
		cout<<ans<<'\n';
	}
	return 0;
}
