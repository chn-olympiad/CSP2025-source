#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long a[100005];
bool vis[100005];
long long n;
long long ans=0;
void dfs(long long mq,long long maxa,long long sum,long long la){
	if(mq>=4){
		if(sum>2*maxa) ans++;
		ans%=MOD;
	}
	for(long long i=la+1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			dfs(mq+1,max(maxa,a[i]),sum+a[i],i);
			vis[i]=false;
		}
	}
}
long long C[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
	}
	else{
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=i;j++){
				if(i==1) C[i][j]=1;
				else if(j==1) C[i][j]=i;
				else C[i][j]=C[i-1][j-1]+C[i-1][j];
				C[i][j]%=MOD;
			}
		}
		long long da=0;
		for(long long i=3;i<=n;i++){
			da+=C[n][i];
			da%=MOD;
		}
		cout<<da;
	}
	return 0;
}
//[40,64]pts 
