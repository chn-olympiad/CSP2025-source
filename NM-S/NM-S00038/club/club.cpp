#include<bits/stdc++.h>
using namespace std;
	const int INF=1e9;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<vector<int> > a(n,vector<int>(3));
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
int mpd=n/2;
vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(mpd+1,vector<int>(mpd+1,-INF)));
dp[0][0][0]=0;
for(int i=0;i<n;i++){
	for(int x=0;x<=mpd;x++){
		for(int y=0;y<=mpd;y++){
			if(dp[i][x][y]==-INF)continue;
			int z=i-x-y;
			if(z<0||z>mpd)continue;
			if(x+1<=mpd){
				dp[i+1][x+1][y]=max(dp[i+1][x+1][y],dp[i][x][y]+a[i][0]);
		       	}
			if(y+1<=mpd){
dp[i+1][x][y+1]=max(dp[i+1][x][y+1],dp[i][x][y]+a[i][1]);
	}
		if(z+1<=mpd){
dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][x][y]+a[i][2]);
	}
		}
	}
}
int ans=0;
for(int x=0;x<=mpd;x++){
    for(int y=0;y<=mpd;y++){
    	int z=n-x-y;
	    if(z>=0&&z<=mpd){
	      ans=max(ans,dp[n][x][y]);
	}
}
}
	cout<<ans<<endl;

}
return 0;}
