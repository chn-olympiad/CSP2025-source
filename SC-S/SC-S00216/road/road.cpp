#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define vamos return 0;
using namespace std;
const int mx=3e5+10;
int t;
struct node{
		int man;
		int bu;
		int ren;
	}m[mx];	
bool cmp(node a,node b){
	return a.man>b.man;
}
void jisuan(int n){	
	int b[mx][4],c[mx][4];
	for(int i=0;i<=mx;i++){
		m[i].bu=0;
		m[i].man=0;
		m[i].ren=0;
		for(int j=0;j<=3;j++) b[i][j]=0,c[i][j]=0;
	}
	int check1[4]={0,0,0,0};
	bool check2[mx];
	for(int i=0;i<=mx;i++) check2[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			int y;
			cin>>y;
			b[i][j]=y;
		}
	}
	int ans2=0;
	for(int i=1;i<=n;i++){
		ans2+=b[i][1];
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			c[i][j+1]=b[i][j+1]-b[i][1];
		}
	}
	int dp[11][6][6];
	for(int i=1;i<=11;i++){
		for(int j=1;j<=6;j++){
			for(int k=1;k<=6;k++){
				dp[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=11;i++){
		for(int j=1;j<=6;j++){
			for(int k=1;k<=6;k++){
				dp[i][j][k]=ans2;
			}	
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n/2);j++){
			for(int k=1;k<=(n/2);k++){
				dp[i][j][k]=max(dp[i-1][j-1][k]+c[i][2],dp[i-1][j][k-1]+c[i][3]);
			}
		}
	}
	cout<<dp[n][n/2][n/2];
	return;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		int n;
		cin>>n; 
		jisuan(n);
	}
	vamos
} 