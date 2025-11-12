#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=505,mod=998244353;
int n,a[N],sum[N],dp[N][N*N];//已经选了i个，和为s 
LL ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){//考虑选不选a[i]
		for(int j=i;j>=1;j--){//已经选了j个 
			for(int s=sum[i];s>=a[i];s--){//和为s
				(dp[j][s]+=dp[j-1][s-a[i]])%=mod;//选 
				if(s>a[i]*2&&j>=3&&dp[j-1][s-a[i]]>0){
					(ans+=dp[j-1][s-a[i]])%=mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//freopen("polygon.in","r",stdin);
/*
本来先打点小作文的，但是bro T3一脸懵，T4调了巨久的dp暴力
那个一个月考了9次模拟赛的2025-10月走了
为了11.1也是调心态调了一周(主要是whk太fw了,马上又要期中考
(OI也是fw 
alrt T4别炸 
*/
