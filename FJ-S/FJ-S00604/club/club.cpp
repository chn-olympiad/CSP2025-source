#include<bits/stdc++.h>
using namespace std;
int t,n,dp[6][100005],c[6][4],a[100005][4];

int cal1(int one,int two,int thr){
	int x=max(one,max(two,thr));
	if(x==one)return 1;
	else if(x==two)return 2;
	else return 3;
}

int cal2(int one,int two,int thr){

	return max(one,max(two,thr));
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	for(int i=1;i<=t;i++){
		cin>>n;
		c[i][1]=n/2,c[i][2]=n/2,c[i][3]=n/2;;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++)
			cin>>a[j][k];
		}
		for(int j=1;j<=n;j++,cout<<endl){
			for(int k=1;k<=3;k++)
			cout<<a[j][k]<<' ';
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=3;l++){
				dp[i][j]=max(dp[i][j],dp[i][c[i][l]-1]+a[j][l]);
			}
			
		}
		cout<<dp[i][n]<<endl;
	}
	return 0;
}
