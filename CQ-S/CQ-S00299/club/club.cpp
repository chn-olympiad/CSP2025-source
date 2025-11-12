#include<bits/stdc++.h>
using namespace std;
//60
#define ll long long
const ll N=1e5+10;
ll dp[110][110][110];//3个 
ll a[N][4];
ll dx[4]={0,-1,0,0};
ll dy[4]={0,0,-1,0};
ll dz[4]={0,0,0,-1};
bool _A=1;
ll n;
void solve2(){
	ll sum=0;
	priority_queue<ll>q;
	for(int i=1;i<=n;i++){
		q.push(a[i][1]);
	}
	n/=2;
	while(n--){
		sum+=q.top();
		q.pop();
	}
	cout<<sum<<endl; 
	exit(0);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j!=1&&a[i][j])_A=0;
		}
	}
	if(_A)solve2();
	memset(dp,-63,sizeof(dp));
	ll ans=0;
	dp[0][0][0]=0;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=min(i,n/2);j++){
			for(ll k=0;k<=n/2&&j+k<=i;k++){
				ll l=i-j-k;
				if(l>n/2)continue;
				if(!j&&!k&&!l)continue;
				ll re=0;
				if(j)re=max(re,dp[j-1][k][l]+a[i][1]);
				if(k)re=max(re,dp[j][k-1][l]+a[i][2]);
				if(l)re=max(re,dp[j][k][l-1]+a[i][3]);
				dp[j][k][l]=re;
				ans=max(ans,re);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
复杂度上界 n log n 

显然是排序

按什么排？排完之后又怎么做？

只打了一个n^3 DP 
*/
