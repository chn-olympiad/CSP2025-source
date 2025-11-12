#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int n;
	int dp[100005][3];
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>dp[i][j];
			}
		}		
	}
	int lx=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			lx+=dp[i][j];
		}
	}
	cout<<lx;
	fclose(stdin);
    fclose(stdout);
	return 0;
} 
