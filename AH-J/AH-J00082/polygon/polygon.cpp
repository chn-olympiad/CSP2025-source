#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
const int N=5005,M=1e4+5,MOD=998244353;
int a[N],f[N],dp[M][3],n,ans=0;
bool flag=true;
void init(int n){
	f[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]*2%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(n<=3){
		int maxn=max(max(a[1],a[2]),a[3]);
		int sum=a[1]+a[2]+a[3];
		if(sum>maxn*2) cout<<"1\n";
		else cout<<"0\n";
		return 0;
	}
	init(n);
	ans=(f[n]-(n*(n-1)/2+n+1))%MOD;
	if(flag){
		cout<<ans<<"\n";
		return 0;
	}
	for(int k=3;k<=n;k++){
		int m=a[k];
		dp[0][0]=1,dp[0][1]=dp[0][2]=0;
		for(int i=1;i<=m;i++) dp[i][0]=dp[i][1]=dp[i][2]=0;
		for(int i=1;i<k;i++){
			for(int j=m;j>=a[i];j--){
				dp[j][1]+=dp[j-a[i]][0];
				dp[j][2]+=max(dp[j-a[i]][1],dp[j-a[i]][2]);
			}
		}
		int tot=0;
		for(int i=1;i<=m;i++) tot+=dp[i][2];
		ans=((ans-tot)%MOD+MOD)%MOD;
	}
	cout<<ans<<"\n";
	return 0;
}
