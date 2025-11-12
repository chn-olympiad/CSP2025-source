#include <bits/stdc++.h>
using namespace std;

int n;

struct st{

    int a, b, c;

};

int t;
st s[100010];
int dp[110][51][51][51];

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
    	memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int j=1; j<=n; j++){
            scanf("%d%d%d", &s[j].a, &s[j].b, &s[j].c);
        }
        for(int j=1; j<=n; j++){
        	for(int k=0; k<=n/2; k++){
        		for(int l=0; l<=n/2; l++){
        			for(int r=0; r<=n/2; r++){
        				if(k>=1){
        					dp[j][k][l][r]=max(dp[j-1][k-1][l][r]+s[j].a, dp[j][k][l][r]);
						}
						if(l>=1){
							dp[j][k][l][r]=max(dp[j-1][k][l-1][r]+s[j].b, dp[j][k][l][r]);
						}
						if(r>=1){
							dp[j][k][l][r]=max(dp[j-1][k][l][r-1]+s[j].c, dp[j][k][l][r]);
						}
					}	
				}
			}
		}
		int ans=0;
		for(int j=1; j<=n/2; j++){
			for(int k=1; k<=n/2; k++){
				for(int l=1; l<=n/2; l++){
					ans=max(ans, dp[n][j][k][l]);
				}
			}
		}
		printf("%d\n", ans);
    }

    return 0;

}
