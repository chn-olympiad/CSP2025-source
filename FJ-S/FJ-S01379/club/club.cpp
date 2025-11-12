#include<bits/stdc++.h>
#define ll long long
#define ifo(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
int t,n,a[100005],b[100005],c[100005],ans[10];
int dp1(){
	int dp[105][105][105],max1=0;
	memset(dp,0,sizeof(dp));
	ifo(i,1,n){
		ifo(j,0,n/2)ifo(k,0,n/2)
			if(j<=i&&k<=i&&j+k<=i){
				if(j>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+a[i]);
				if(k>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+b[i]);
				if(i-j-k>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+c[i]);
				max1=max(max1,dp[j][k][i-j-k]);
			}
	}
	return max1;
}
bool cmp(int a1,int b1){return a1>b1;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>t;
	ifo(i,1,t){
		cin>>n;
		int a1=0,b1=0,c1=0;
		ifo(j,1,n){
			cin>>a[j]>>b[j]>>c[j];
			a1+=a[j],b1+=b[j],c1+=c[j];
		}
		if(n<=200)ans[i]=dp1();
		else if(b1==0&&c1==0){
			sort(a+1,a+1+n,cmp);
			ifo(j,1,n/2)ans[i]+=a[j];
		}
	}
	ifo(i,1,t)cout<<ans[i]<<'\n';
	return 0;
} 
