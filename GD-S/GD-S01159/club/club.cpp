#include<bits/stdc++.h>
using namespace std;
const int N=200;
int t,n,ans,dp[N+5][N/2+5][N/2+5];
bool pfA=1,pfB=1;
struct member{
	int part[4];
}a[N];
bool cmpA(member x,member y){return x.part[1]>y.part[1];}
bool cmp(member x,member y){return x.part[1]+x.part[2]+x.part[3]>y.part[1]+y.part[2]+y.part[3];}
void A(){
	sort(a+1,a+1+n,cmpA);
	for(int i=1;i<=n/2;i++) ans+=a[i].part[1];
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].part[1]>>a[i].part[2]>>a[i].part[3];
			if(a[i].part[2]>0) pfA=0;
			if(a[i].part[3]>0) pfB=0;
		}
		if(pfA&&pfB){A();return 0;}
		memset(dp,0,sizeof(dp));ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i-j,n/2);k++){
					if(i-j-k<0) break;
					if(i-j-k>n/2) continue;
					if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].part[1]);
					if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].part[2]);
					if(i-j-k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].part[3]);
					//cout<<i<<"  "<<j<<' '<<k<<' '<<i-j-k<<"  "<<dp[i][j][k]<<'\n';
					if(i==n) ans=max(ans,dp[i][j][k]);
				}
				//cout<<'\n';
			}
			//cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
