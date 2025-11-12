#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353,N1=510,N2=5010,M=5e4+10;
int n,a[N2+10],dp1[N1+10][M+10],dp2[N2+10][N2+10],ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	if(n<=500){
		dp1[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=sum;j++){
				dp1[i][j]=(dp1[i][j]+dp1[i-1][j])%MOD;
				if(j>=a[i]){
					dp1[i][j]=(dp1[i][j]+dp1[i-1][j-a[i]])%MOD;
				}
			}
		}
		for(int i=1;i<=sum;i++){
			int j=n;
			while(2*a[j]>=i&&j>0){
				j--;
			}
			ans=(ans+dp1[j][i])%MOD;
		}
		cout<<ans;
	}
	else{
		dp2[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=sum;j++){
				dp2[i][j]=(dp2[i][j]+dp2[i-1][j])%MOD;
				if(j>=a[i]){
					dp2[i][j]=(dp2[i][j]+dp2[i-1][j-a[i]])%MOD;
				}
			}
		}
		for(int i=1;i<=sum;i++){
			int j=n;
			while(2*a[j]>=i&&j>0){
				j--;
			}
			ans=(ans+dp2[j][i])%MOD;
		}
		cout<<ans;
	}
	return 0;
}
/*
5
1 2 3 4 5

9

5
2 2 3 8 10

6

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

1042392

3
1 1 1

1

4
1 2 2 1

3
*/
