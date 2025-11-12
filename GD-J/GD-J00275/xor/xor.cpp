#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k,a[N+10],b,sum[N+10][21],sk[21],dp[N+10];
bool check(int r,int l){
	for(int i=0;i<=20;i++){
		if(sk[i]!=sum[r][i]^sum[l][i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	b=k;
	int x=0;
	while(b){
		sk[x++]=b%2;
		b/=2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=a[i];
		int x=0;
		for(int j=0;j<=20;j++){
			sum[i][j]=sum[i-1][j];
		}
		while(b){
			sum[i][x++]^=(b%2);
			b/=2;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<i;j++){
			if(check(i,j)){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
/*
4 2
2 1 0 3

2

4 3
2 1 0 3

2

4 0
2 1 0 3

1

6 0
0 2 0 2 0 2

3
*/
