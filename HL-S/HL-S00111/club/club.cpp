#include<bits/stdc++.h>
using namespace std;
long long t,n,abc[10][100005],x[10][100005];
long long one(int a,int b,int c){
	if(a>=b && a>=c)return 1;
	if(b>=a && b>=c)return 2;
	if(c>=a && c>=b)return 3;
}
long long two(int a,int b,int c){
	if((a<=b && a>=c) || (a>=b && a<=c))return 1;
	if((b<=a && b>=c) || (b>=a && b<=c))return 2;
	if((c<=b && c>=a) || (c>=b && c<=a))return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>abc[1][j]>>abc[2][j]>>abc[3][j];
		}
		for(int j=1;j<=n;j++){
			x[one(abc[1][j],abc[2][j],abc[3][j])][j]=1;
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				if(x[k][j]=1)x[k][n+1]++;
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				if(x[k][j]=1){
					x[4][j]=abc[k][j]-abc[two(abc[1][j],abc[2][j],abc[3][j])][j];
				}
			}
		}
		while(max(x[1][n+1],max(x[2][n+1],x[3][n+1]))>n/2){
			long long q=1e9,y;
			for(int j=1;j<=n;j++){
				if(x[4][j]<q){
					q=x[4][j];
					y=j;
					x[4][j]=1e9;
				}
			}
			x[one(abc[1][y],abc[2][y],abc[3][y])][y]=0;
			x[two(abc[1][y],abc[2][y],abc[3][y])][y]=1;
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				if(x[k][j]=1){
					abc[k][n+1]+=abc[k][j];
				}
			}
		}
		cout<<abc[1][n+1]+abc[2][n+1]+abc[3][n+1];
	}
	return 0;
}
