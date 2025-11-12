#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005,inf=0x3f3f3f3f3f3f;
int T,n,dp[6][N],curA,curB,curC,maxx=-inf;
struct people{
	int agree1;
	int agree2;
	int agree3;
}a[N];
bool cmp_A_B_C(people x,people y){
	if(x.agree1==y.agree1){
		if(x.agree2==y.agree2) return x.agree3>y.agree3;
		else return x.agree2>y.agree2;
	}
	return x.agree1>y.agree1;
}
bool cmp_A_C_B(people x,people y){
	if(x.agree1==y.agree1){
		if(x.agree3==y.agree3) return x.agree2>y.agree2;
		else return x.agree3>y.agree3;
	}
	return x.agree1>y.agree1;
}
bool cmp_B_A_C(people x,people y){
	if(x.agree2==y.agree2){
		if(x.agree1==y.agree1) return x.agree3>y.agree3;
		else return x.agree1>y.agree1;
	}
	return x.agree2>y.agree2;
}
bool cmp_B_C_A(people x,people y){
	if(x.agree2==y.agree2){
		if(x.agree3==y.agree3) return x.agree1>y.agree1;
		else return x.agree3>y.agree3;
	}
	return x.agree2>y.agree2;
}
bool cmp_C_A_B(people x,people y){
	if(x.agree3==y.agree3){
		if(x.agree1==y.agree1) return x.agree2>y.agree2;
		else return x.agree2>y.agree2;
	}
	return x.agree3>y.agree3;
}
bool cmp_C_B_A(people x,people y){
	if(x.agree3==y.agree3){
		if(x.agree2==y.agree2) return x.agree1>y.agree1;
		else return x.agree2>y.agree2;
	}
	return x.agree3>y.agree3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i].agree1);
			scanf("%lld",&a[i].agree2);
			scanf("%lld",&a[i].agree3);
		}
		curA=0,curB=0,curC=0;
		sort(a+1,a+1+n,cmp_A_B_C);
		for(int i=1;i<=n;i++){
			if(curA==n/2){
				if(a[i].agree2>a[i].agree3){
					curB++;
					dp[0][i]=dp[0][i-1]+a[i].agree2;
				}
				else{
					curC++;
					dp[0][i]=dp[0][i-1]+a[i].agree3;
				}
			}
			else{
				curA++;
				dp[0][i]=dp[0][i-1]+a[i].agree1;
			}
		}
		curA=0,curB=0,curC=0;
		sort(a+1,a+1+n,cmp_A_C_B);
		for(int i=1;i<=n;i++){
			if(curA==n/2){
				if(a[i].agree3>a[i].agree2){
					curC++;
					dp[1][i]=dp[1][i-1]+a[i].agree3;
				}
				else{
					curB++;
					dp[1][i]=dp[1][i-1]+a[i].agree2;
				}
			}
			else{
				curA++;
				dp[1][i]=dp[1][i-1]+a[i].agree1;
			}
		}
		curA=0,curB=0,curC=0;
		sort(a+1,a+1+n,cmp_B_A_C);
		for(int i=1;i<=n;i++){
			if(curB==n/2){
				if(a[i].agree1>a[i].agree3){
					curA++;
					dp[2][i]=dp[2][i-1]+a[i].agree1;
				}
				else{
					curC++;
					dp[2][i]=dp[2][i-1]+a[i].agree3;
				}
			}
			else{
				curB++;
				dp[2][i]=dp[2][i-1]+a[i].agree2;
			}
		}
		curA=0,curB=0,curC=0;
		sort(a+1,a+1+n,cmp_B_C_A);
		for(int i=1;i<=n;i++){
			if(curB==n/2){
				if(a[i].agree3>a[i].agree1){
					curC++;
					dp[3][i]=dp[3][i-1]+a[i].agree3;
				}
				else{
					curA++;
					dp[3][i]=dp[3][i-1]+a[i].agree1;
				}
			}
			else{
				curB++;
				dp[3][i]=dp[3][i-1]+a[i].agree2;
			}
		}
		curA=0,curB=0,curC=0;
		sort(a+1,a+1+n,cmp_C_A_B);
		for(int i=1;i<=n;i++){
			if(curC==n/2){
				if(a[i].agree1>a[i].agree2){
					curA++;
					dp[4][i]=dp[4][i-1]+a[i].agree1;
				}
				else{
					curB++;
					dp[4][i]=dp[4][i-1]+a[i].agree2;
				}
			}
			else{
				curC++;
				dp[4][i]=dp[4][i-1]+a[i].agree3;
			}
		}
		curA=0,curB=0,curC=0;
		sort(a+1,a+1+n,cmp_C_B_A);
		for(int i=1;i<=n;i++){
			if(curC==n/2){
				if(a[i].agree2>a[i].agree1){
					curB++;
					dp[5][i]=dp[5][i-1]+a[i].agree2;
				}
				else{
					curA++;
					dp[5][i]=dp[5][i-1]+a[i].agree1;
				}
			}
			else{
				curC++;
				dp[5][i]=dp[5][i-1]+a[i].agree3;
			}
		}
		maxx=-inf;
		for(int i=0;i<6;i++) maxx=max(maxx,dp[i][n]);
		printf("%lld\n",maxx);
	}
    return 0;
}
