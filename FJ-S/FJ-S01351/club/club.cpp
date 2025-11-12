#include <bits/stdc++.h>
using namespace std;

struct mb{
	int bm1;
	int bm2;
	int bm3;
	int id;	
}bm[1000005];
int N,n2;
int bm1r,bm2r,bm3r;
int dp[1000005]
int a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>N;
	for(int cce=0;cce<N;cce++){
		int n=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>bm[i].bm1>>bm[i].bm2>>bm[i].bm3;
			bm[i].id=i;
		}
		n2=n/2
		dp[0]=max(bm[0].bm3,max(bm[0].bm1,bm[0].bm2))
		for(int i=0;i<n;i++){
			dp[i]=max(max(dp[i-1]+bm[i].bm1,dp[i-1]+bm[i].bm2),dp[i-1]+bm[i].bm3)
		}
		cout<<dp[n];
	}
	return 0;
}



