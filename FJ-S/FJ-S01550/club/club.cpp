#include<bits/stdc++.h>
using namespace std;
const int M1=1e2+1,M2=5e1+1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int DP[M1][M2][M2][M2]={};
		int a[3][M1]={};
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
		}
		for(int i=1;i<=n;i++){
			for(int w1=0;w1<=min(i,n/2);w1++){
				for(int w2=0;w2<=min(i,n/2);w2++){
					for(int w3=0;w3<=min(i,n/2);w3++){
						if(w1>=1)
						DP[i][w1][w2][w3]=max(DP[i-1][w1-1][w2][w3]+a[0][i],DP[i][w1][w2][w3]);
						if(w2>=1)
						DP[i][w1][w2][w3]=max(DP[i-1][w1][w2-1][w3]+a[1][i],DP[i][w1][w2][w3]);
						if(w3>=1)
						DP[i][w1][w2][w3]=max(DP[i-1][w1][w2][w3-1]+a[2][i],DP[i][w1][w2][w3]);
					}	
				}
			}
		}
		cout<<DP[n][n/2][n/2][n/2]<<endl;
	}
}
