#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int a[MAXN],n,k,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int dp[n][n]={0},inde=1;
	for(int i=0;i<n;i++){
		bool flag=true;
		for(int j=0;j<inde;j++){
			dp[i][j]=a[i];
			if(inde>1&&j!=0&&i!=0){
				dp[i][j]^=dp[i-1][j-1];
			}
			if(dp[i][j]==k){
				cnt++;
				inde=1;
				flag=false;
				break;
			}
		}
		if(flag){
			inde++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
