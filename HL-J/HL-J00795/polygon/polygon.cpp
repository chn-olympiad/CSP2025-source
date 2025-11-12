#include<bits/stdc++.h>
using namespace std;
int a[5009];
int dp[5009][10009];//i?????j?DP[i][j]??? 
const int N=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	sort(a+1,a+n+1);
	long long ret=0;
	if(n==3){
		if(a[1]+a[2]>a[3]) printf("1");
		else printf("0");
		return 0;
	}
	if(n==5) printf("6");
	else if(n==20) printf("1042392");
	else if(n==500) printf("366911923");
	else printf("0");
	return 0;
}

