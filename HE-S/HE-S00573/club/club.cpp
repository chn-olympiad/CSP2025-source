#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N][3];
int dp[N], st[N];
int n, res=0;

void work(){
	for(int k=1; k<=3; k++){
		for(int i=1; i<=n; i++){
			st[i]=true;
			for(int j=n; j>n/2; j--){
				dp[j]=max(dp[j], dp[j-1]+a[i][k]);
			}
		}
	}
	cout<<dp[n]<<endl;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin>>T;
	while(T--){
		memset(a, 0x3f, sizeof(a));
		memset(dp, 0, sizeof(dp));
		res=0;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		work(); 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
