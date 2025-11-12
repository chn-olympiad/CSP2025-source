#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define st first
#define nd second
const int N=1e5+5,M=7.85e2+5;
int a[N][4];
int n;
int dp[M][M][M];
int ans;
void solve(){
	cin>>n;
	ans=0;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	//for(int i=1;i<=3;i++)dp[1][i]=a[1][i];
	dp[1][0][0]=a[1][1];
	dp[0][1][0]=a[1][2];
	dp[0][0][1]=a[1][3];
	int n2=n/2;
	for(int i=2;i<=n;i++){
		int n3=n/2;
		for(int b=n3;b>=0;b--){
			for(int c=n3;c>=0;c--){
				int d=i-b-c;
				if(d*2>n||d<0)continue;
				//cout<<"check:"<<dp[b][c][d]<<' '<<dp[b-1][c][d]+a[i][1]<<endl;
				if(b>0)dp[b][c][d]=max(dp[b][c][d],dp[b-1][c][d]+a[i][1]);
				if(c>0)dp[b][c][d]=max(dp[b][c][d],dp[b][c-1][d]+a[i][2]);
				if(d>0)dp[b][c][d]=max(dp[b][c][d],dp[b][c][d-1]+a[i][3]);
				//if(b>0||c>0||d>0)cout<<"dp["<<b<<"]["<<c<<"]["<<d<<"]="<<dp[b][c][d]<<endl;
				ans=max(ans,dp[b][c][d]);
			}
		}//cout<<"NEW"<<endl;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}cout<<flush;
	fclose(stdin);fclose(stdout); 
	return 0;
} 
