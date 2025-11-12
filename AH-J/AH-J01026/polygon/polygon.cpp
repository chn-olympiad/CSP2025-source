#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353 ;
long long n , a[5005] , ans , C[3005][3005];//, asdf[5005] , cnt ;//, sum[50005] , dp[5005][5005] ;
bool flag1=1 ;
void dfs(long long i , long long nm , long long sum){
	if(i==nm){
		if(sum>a[nm]){
			// for(int i=1;i<=cnt;i++)cout << asdf[i] << " " ;
			// cout << "\n" ;
			// cout << sum << ' ' << a[nm] << "\n" ;
			ans++;
			// cout << "\n" ;
		}
		return;
	}
	// asdf[++cnt]=i;
	dfs(i+1,nm,sum+a[i]);//选
	// cnt--;
	dfs(i+1,nm,sum);//不选
}
void init(){
	for(int i=1;i<=n;i++)C[i][1]=C[i][i]=1;
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	init();//杨辉三角预处理
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		// sum[i]=sum[i-1]+a[i];
		if(a[i]>1)flag1=0;
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(n==3)
			if(a[1]+a[2]+a[3]>a[3]*2)printf("1");
			else printf("0");
		else printf("0");
	}
	else if(n<=20){
		for(int i=3;i<=n;i++){
			dfs(1,i,0);
		}
		printf("%lld",ans%MOD);
	}
	else if(flag1){
		long long ans=0 ;
		for(int i=3;i<=n;i++){
			for(int j=2;j<=i;j++){
				ans=(ans+C[i][j])%MOD;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
//mjw保佑我csp上300
//mjwyyds