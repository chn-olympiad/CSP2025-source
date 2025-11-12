#include<bits/stdc++.h>
using namespace std;
int q;
int w,e[10005][4];
int dp[10005][10005];
int m[10005][4][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>w;	
		for(int j=1;j<=w;j++){
			for(int d=1;d<=w;d++){
				dp[j][d]=0;
				
			}
			for(int d=1;d<=3;d++){
				for(int b=1;b<=3;b++){
					m[j][d][b]=0;
				}
			}
		}
		for(int j=1;j<=w;j++){
			cin>>e[j][1]>>e[j][2]>>e[j][3];
		} 
		for(int j=1;j<=w;j++){//ÎïÆ·id	
			for(int d=1;d<=3;d++){//now	
				for(int c=1;c<j;c++)
				for(int b=1;b<=3;b++){//±³°üid last					
					if(dp[c][b]+e[j][d]>dp[j][d]&&m[c][b][d]+1<=w/2){
							dp[j][d]=dp[c][b]+e[j][d];
							m[j][d][d]=m[c][b][d]+1;	
						if(d==1){m[j][d][2]=m[c][b][2];m[j][d][3]=m[c][b][3];}	
						if(d==2){m[j][d][1]=m[c][b][1];m[j][d][3]=m[c][b][3];}
						if(d==3){m[j][d][1]=m[c][b][1];m[j][d][2]=m[c][b][2];}					
					}
				}
			}	
		}
		cout<<max(dp[w][1],max(dp[w][2],dp[w][3]))<<endl;
	}
	
	return 0;
}
