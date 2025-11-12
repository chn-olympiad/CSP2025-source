//GZ-S00034安顺市第一高级中学保佳乐
#include <bits/stdc++.h>
using namespace std;
int t,n,dp[10000][10],r[1000],k,m;

int main(){
	cin>>t;
	for(int o=1;o<=t;o++){
		int p[5],m=n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>dp[i][j];
			}
		}

		for(int i=1;i<=n;i++){
			k=dp[i][1];
			m=1;
			for(int j=2;j<=3;j++){
				if(dp[i][j]>k&&p[j]<=n/2){
					k=dp[i][j];
					m=j;
				}
			}
			r[o]+=k;
			p[m]++;
			dp[i][1]=0;
			dp[i][2]=0;
			dp[i][3]=0;
		}

	}
	for(int i=1;i<=t;i++){
			cout<<r[i]<<endl;
		}
	return 0;
}
