#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5010,MOD=998244353;
LL n,ans;
int a[N],c[N][N];
bool flag=1;
void dfs(int s,int t,int la,int sum,int mx){
	if(t==s){
		if(sum>mx*2) ans++;
		return;
	}
	for(int i=la+1;i<=n-(s-t)+1;i++){
		dfs(s,t+1,i,sum+a[i],max(mx,a[i]));
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(n<=3){
		if(n==3 && a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1;
		else cout<<0;
	}else if(flag){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(j==1) c[i][j]=i;
				else if(i==j) c[i][j]=1;
				else c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
			}
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+c[n][i])%MOD;
		}
		cout<<ans;
	}else{
		for(int i=3;i<=n;i++){
			dfs(i,0,0,0,0);
		}
		cout<<ans%MOD;
	}

	return 0;
}
