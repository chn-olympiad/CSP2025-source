#include <bits/stdc++.h>
using namespace std;

int JS(int a,int b){
	int c,a2=2;
	while(a || b){
		if((a&1) != (b&1))
		    c+=a2;
		a2*=2;
	}
	return c;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,a[500005]{};
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	cout << 1;
	int dp[1005][1005]{},ans=0;
	for (int i=2;i<=n;i++){
		dp[i-1][i]=JS(a[i],a[i-1]);
		dp[i][i]=a[i];
	}
	dp[1][1]=a[i];
	
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=i;k<j;k++){
				dp[i][j]=max(dp[i][j],JS(dp[i][k],dp[k+1][j]));
			} 
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
