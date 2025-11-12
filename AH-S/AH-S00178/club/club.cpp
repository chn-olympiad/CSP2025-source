#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 10001

using namespace std;
int a[N][4],n;
int dp[N][4];

int b[N],c[N],tmp[N];

int ans;
void solve(){
	ans=0;
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	bool judge[N];
	bool d=true;
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		b[i]=a[i][2];c[i]=a[i][3];tmp[i]=a[i][1];
		if(b[i]==0&&c[i]==0) judge[i]=true;
		else judge[i]=false;
		d&=judge[i];
	}
	if(d){
		sort(tmp+1,tmp+n+1);
		for(int i=n;i>=n/2+1;--i)
			ans+=tmp[i];
		cout<<ans;
		return ;
	}
	
	if(n==2){
		cout<<max(max(max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),a[1][2]+a[2][1]),a[1][2]+a[2][3]),a[1][3]+a[2][1]),a[1][3]+a[2][2]);
		return ;
	}
	dp[0][1]=dp[0][2]=dp[0][3]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][j];
		}
	}
	cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	return ;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;

	while(t--)
		solve();
	return 0;
}
