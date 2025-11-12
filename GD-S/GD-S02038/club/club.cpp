#include<bits/stdc++.h>
using namespace std;
const int MAX=2e4+5;
int t,n,a[MAX][4];
long long dp[MAX][4];
void below30(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			dp[i][j]=max({dp[i-1][1],dp[i-1][2],dp[i-1][3]})+a[i][j];
		}
	}
	printf("%lld",max({dp[n][3],dp[n][1],dp[n][2]}));
}
void A(){
	int temp[100005];
	for(int i=1;i<=n;i++){
		temp[i]=a[i][1];
	}
	sort(temp+1,temp+n+1,greater<int>());
	long long sum=0;
	for(int i=1;i<=n/2;i++){
		sum+=temp[i];
	}
	printf("%lld",sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool f=false;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) f=true;
		}
		if(!f){
			A();
		}
		else below30();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
